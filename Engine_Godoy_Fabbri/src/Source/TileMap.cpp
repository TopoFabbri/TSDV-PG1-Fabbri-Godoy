#include "TileMap.h"

#include <algorithm>
#include <iostream>

#include "TextureImporter.h"
#include "tinyxml2.h"

namespace ToToEng
{
    TileMap::TileMap(Renderer* renderer)
    {
        this->renderer = renderer;
        
        width = 0;
        height = 0;
        tileWidth = 0;
        tileHeight = 0;
        texture = 0;
        imageWidth = 0;
        imageHeight = 0;
        convertedPosX = 0;
        convertedPosY = 0;
    }

    TileMap::~TileMap() = default;

    const Tile& TileMap::tile(const unsigned int uiId)
    {
        for (int i = 0; i < tiles.size(); i++)
        {
            if (uiId == tiles[i].getId()) return tiles[i];
        }

        throw std::runtime_error("Tile not found");
    }

    void TileMap::setMapTileId(int layer, unsigned int uiCol, unsigned int uiRow, unsigned int uiId)
    {
        tileMapGrid[layer][uiCol][uiRow] = tile(uiId);
    }

    void TileMap::setTile(const Tile& rkTile)
    {
        tiles.push_back(rkTile);
    }

    void TileMap::setTileDimensions(const float tileWidth, const float tileHeight)
    {
        this->tileWidth = tileWidth;
        this->tileHeight = tileHeight;
    }

    void TileMap::setDimensions(const float width, const float height)
    {
        this->width = static_cast<unsigned int>(round(width));
        this->height = static_cast<unsigned int>(round(height));

        tileMapGrid.emplace_back(this->height, std::vector<Tile>(this->width, Tile(renderer)));
    }

    void TileMap::setTexture(const unsigned int texture)
    {
        this->texture = texture;
    }

    void TileMap::draw()
    {
        const float mapWidth = -(static_cast<float>(width) * tileWidth) / 2;
        const float mapHeight = static_cast<float>(height) * tileHeight / 2;

        for (int i = 0; i < tileMapGrid.size(); i++)
        {
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    if (tileMapGrid[i][y][x].getId() != NULL)
                    {
                        tileMapGrid[i][y][x].setPosX(mapWidth + tileWidth * x);
                        tileMapGrid[i][y][x].setPosY(mapHeight - tileHeight * y);
                        tileMapGrid[i][y][x].draw();
                    }
                }
            }
        }
    }

    bool TileMap::importTileMap(std::string filePath)
    {
        tinyxml2::XMLDocument doc; //guarda el documento
        tinyxml2::XMLError errorHandler; //guarda el resultado de las funciones

        errorHandler = doc.LoadFile(filePath.c_str()); //carga el archivo XML
        if (errorHandler == tinyxml2::XML_ERROR_FILE_NOT_FOUND || errorHandler == tinyxml2::XML_ERROR_FILE_COULD_NOT_BE_OPENED) return false;

        // Loading Map element and save Map width, heigth in tiles and width, heigth of Tiles in pixels
        tinyxml2::XMLElement* mapNode = doc.FirstChildElement("map");
        if (mapNode == nullptr) return false;
        setDimensions(mapNode->FloatAttribute("width"), mapNode->FloatAttribute("height")); // Get width and heigth for
        setTileDimensions(mapNode->FloatAttribute("tilewidth"), mapNode->FloatAttribute("tileheight")); // the map and the tiles

        // Loading Tilset element
        tinyxml2::XMLElement* pTileset = mapNode->FirstChildElement("tileset");
        if (pTileset == NULL) return false;

        int tileCount = pTileset->IntAttribute("tilecount"); // Number of Tiles in the Tileset
        int columns = pTileset->IntAttribute("columns"); // Columns of Tiles in the Tileset
        int rows = tileCount / columns;

        imagePath = "Assets/"; //
        imagePath += pTileset->FirstChildElement("image")->Attribute("source"); // Loading Textures
        setTexture(TextureImporter::loadTexture(imagePath.c_str()));

        imageWidth = pTileset->FirstChildElement("image")->IntAttribute("width");
        imageHeight = pTileset->FirstChildElement("image")->IntAttribute("height");
        float tileX = 0.0f, tileY = 0.0f;
        int id = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                Tile newTile(renderer);

                newTile.setId(id);
                newTile.setTexture(texture);
                newTile.setScale({tileWidth, tileHeight});

                newTile.setOffset({tileX, tileY});

                tileX += tileWidth;
                setTile(newTile);
                id++;
            }
            tileX = 0;
            tileY += tileHeight;
        }

        tinyxml2::XMLElement* pTile = pTileset->FirstChildElement("tile");

        while (pTile)
        {
            unsigned int id = pTile->IntAttribute("id");
            tinyxml2::XMLElement* pProperty = pTile->FirstChildElement("properties")->FirstChildElement("property");
            std::string propertyName = pProperty->Attribute("value");
            if (propertyName == "false") tiles[id].walkability(false);
            else tiles[id].walkability(true);

            pTile = pTile->NextSiblingElement("tile");
        }

        // Loading Layer element
        tinyxml2::XMLElement* pLayer = mapNode->FirstChildElement("layer");
        if (pLayer == NULL) return false;

        int layerCount = 0;
        while (pLayer)
        {
            // Loading Data element
            tinyxml2::XMLElement* pData = pLayer->FirstChildElement("data");
            if (pData == NULL) return false;

            if (layerCount > 0)
            {
                tileMapGrid.emplace_back(height, std::vector<Tile>(width, Tile(renderer)));
            }

            while (pData)
            {
                std::vector<int> tileGids;
                for (tinyxml2::XMLElement* pTile = pData->FirstChildElement("tile"); pTile != NULL; pTile = pTile->NextSiblingElement("tile"))
                {
                    unsigned int gid = std::atoi(pTile->Attribute("gid")); // tile's id is saved
                    tileGids.push_back(gid);
                }

                int gid = 0;
                for (uint y = 0; y < height; y++)
                {
                    for (uint x = 0; x < width; x++)
                    {
                        if (tileGids[gid] != 0) setMapTileId(layerCount, y, x, tileGids[gid]);
                        gid++;
                    }
                }

                pData = pData->NextSiblingElement("data");
            }
            layerCount++;
            pLayer = pLayer->NextSiblingElement("layer");
        }

        return true;
    }
}
