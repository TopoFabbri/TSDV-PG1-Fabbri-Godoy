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

        tiles = std::vector<Tile>();
    }

    TileMap::~TileMap()
    {
        for (Tile** layer : tileMapGrid)
        {
            if (layer)
            {
                for (unsigned int i = 0; i < height; i++)
                {
                    delete[] layer[i];
                }
                delete[] layer;
            }
        }
        tileMapGrid.clear();
    }

    const Tile& TileMap::tile(const unsigned int uiId)
    {
        Tile* noTile = nullptr;

        for (const Tile& tile : tiles)
        {
            if (uiId == tile.getId())
                return tile;
        }

        return *noTile;
    }

    void TileMap::setMapTileId(int layer, unsigned int uiCol, unsigned int uiRow, unsigned int uiId)
    {
        Tile tileOfId = tile(uiId);
        
        tileMapGrid[layer][uiCol][uiRow].setId(uiId);
        tileMapGrid[layer][uiCol][uiRow].setOffset(tileOfId.uvOffset);
        tileMapGrid[layer][uiCol][uiRow].setScale(tileOfId.uvScale);
        tileMapGrid[layer][uiCol][uiRow].setTexture(texture, imageWidth, imageHeight);
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
    
        Tile** tileMap = new Tile*[this->height];
    
        for (uint i = 0; i < this->height; i++)
        {
            tileMap[i] = new Tile[this->width]();
            
            for (unsigned int j = 0; j < this->width; j++)
                tileMap[i][j].setRenderer(renderer);
        }
        
        tileMapGrid.push_back(tileMap);
    }

    void TileMap::setTexture(const unsigned int texture)
    {
        this->texture = texture;
    }

    void TileMap::draw() const
    {
        const float mapWidth = -(static_cast<float>(width) * tileWidth) / 2;
        const float mapHeight = static_cast<float>(height) * tileHeight / 2;

        for (uint i = 0; i < tileMapGrid.size(); i++)
        {
            for (uint y = 0; y < height; y++)
            {
                for (uint x = 0; x < width; x++)
                {
                    if (tileMapGrid[i][y][x].getId() == NULL) continue;
                    
                    tileMapGrid[i][y][x].setPosX(mapWidth + tileWidth * static_cast<float>(x));
                    tileMapGrid[i][y][x].setPosY(mapHeight - tileHeight * static_cast<float>(y));
                    tileMapGrid[i][y][x].draw();
                }
            }
        }
    }

    bool TileMap::importTileMap(std::string filePath)
    {
        tinyxml2::XMLDocument doc;

        const tinyxml2::XMLError errorHandler = doc.LoadFile(filePath.c_str());
        
        if (errorHandler == tinyxml2::XML_ERROR_FILE_NOT_FOUND || errorHandler == tinyxml2::XML_ERROR_FILE_COULD_NOT_BE_OPENED) return false;

        tinyxml2::XMLElement* mapNode = handleImportMapAttributes(doc);
        if (mapNode == nullptr)
            return false;
        
        tinyxml2::XMLElement* pTileset = handleImportTileset(mapNode);
        if (pTileset == nullptr)
            return false;
        
        handleImportTiles(pTileset);

        // Loading Layer element
        tinyxml2::XMLElement* pLayer = mapNode->FirstChildElement("layer");
        if (pLayer == nullptr) return false;

        return handleImportMapData(pLayer);
    }

    tinyxml2::XMLElement* TileMap::handleImportMapAttributes(tinyxml2::XMLDocument& doc)
    {
        tinyxml2::XMLElement* mapNode = doc.FirstChildElement("map");
        
        if (mapNode == nullptr)
            return nullptr;
        
        setDimensions(mapNode->FloatAttribute("width"), mapNode->FloatAttribute("height"));
        setTileDimensions(mapNode->FloatAttribute("tilewidth"), mapNode->FloatAttribute("tileheight"));
        
        return mapNode;
    }

    tinyxml2::XMLElement* TileMap::handleImportTileset(tinyxml2::XMLElement* mapNode)
    {
        tinyxml2::XMLElement* pTileset = mapNode->FirstChildElement("tileset");
        if (pTileset == nullptr) return pTileset;

        int tileCount = pTileset->IntAttribute("tilecount"); // Number of Tiles in the Tileset
        int columns = pTileset->IntAttribute("columns"); // Columns of Tiles in the Tileset
        int rows = tileCount / columns;

        imagePath = pTileset->FirstChildElement("image")->Attribute("source"); // Loading Textures
        setTexture(TextureImporter::loadTexture(imagePath.c_str()));

        imageWidth = pTileset->FirstChildElement("image")->IntAttribute("width");
        imageHeight = pTileset->FirstChildElement("image")->IntAttribute("height");

        tiles.clear();
        tiles.reserve(tileCount);

        float tileX = 0.0f, tileY = 0.0f;
        int id = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                Tile newTile = Tile(renderer);

                newTile.setId(id);
                newTile.setTexture(texture, imageWidth, imageHeight);
                newTile.setScale({tileWidth / static_cast<float>(imageWidth), tileHeight / static_cast<float>(imageHeight)});

                newTile.setOffset({tileX / static_cast<float>(imageWidth), tileY / static_cast<float>(imageHeight)});

                tileX += tileWidth;
                setTile(newTile);
                id++;
            }
            tileX = 0;
            tileY += tileHeight;
        }
        return pTileset;
    }

    bool TileMap::handleImportMapData(tinyxml2::XMLElement*& pLayer)
    {
        int layerCount = 0;
        
        while (pLayer)
        {
            // Loading Data element
            tinyxml2::XMLElement* pData = pLayer->FirstChildElement("data");
            if (pData == nullptr) return true;

            initializeLayer(layerCount);

            for (tinyxml2::XMLElement* pData = pLayer->FirstChildElement("data"); 
                 pData != nullptr; 
                 pData = pData->NextSiblingElement("data"))
            {
                std::vector<int> tileGids;

                const char* encoding = pData->Attribute("encoding");

                if (encoding && std::string(encoding) == "csv")
                    handleCsvTileImport(pData, tileGids);
                else
                    handleEmbeddedTileImport(pData, tileGids);

                if (tileGids.empty())
                    continue;

                setTiles(layerCount, tileGids);
            }
            
            layerCount++;
            pLayer = pLayer->NextSiblingElement("layer");
        }
        return false;
    }

    void TileMap::handleImportTiles(tinyxml2::XMLElement* pTileset)
    {
        tinyxml2::XMLElement* pTile = pTileset->FirstChildElement("tile");

        while (pTile)
        {
            uint id = pTile->IntAttribute("id");
            tinyxml2::XMLElement* pProperty = pTile->FirstChildElement("properties")->FirstChildElement("property");
            std::string propertyName = pProperty->Attribute("value");
            if (propertyName == "false") tiles[id].walkability(false);
            else tiles[id].walkability(true);

            pTile = pTile->NextSiblingElement("tile");
        }
    }

    void TileMap::initializeLayer(int layerCount)
    {
        if (layerCount >= 0)
        {
            Tile** tileMap;
            tileMap = new Tile*[height];
            for (uint i = 0; i < height; i++)
            {
                tileMap[i] = new Tile[width]();

                for (uint j = 0; j < width; j++)
                    tileMap[i][j].setRenderer(renderer);
            }

            tileMapGrid.push_back(tileMap);
        }
    }

    void TileMap::handleCsvTileImport(tinyxml2::XMLElement* pData, std::vector<int>& tileGids)
    {
        const char* csvText = pData->GetText();
        std::string textStr = csvText ? csvText : "";
        std::stringstream ss(textStr);
        std::string value;

        while (std::getline(ss, value, ','))
            if (!value.empty()) tileGids.push_back(std::stoi(value));
    }

    void TileMap::handleEmbeddedTileImport(tinyxml2::XMLElement* pData, std::vector<int> tileGids)
    {
        for (tinyxml2::XMLElement* pTileGid = pData->FirstChildElement("tile"); pTileGid != nullptr; pTileGid = pTileGid->NextSiblingElement("tile"))
        {
            const char* gidAttribute = pTileGid->Attribute("gid");
            int gid = gidAttribute != nullptr ? std::atoi(gidAttribute) : 0;

            tileGids.push_back(gid);
        }
    }

    void TileMap::setTiles(int layerCount, std::vector<int> tileGids)
    {
        int gid = 0;
                
        for (unsigned int y = 0; y < height; y++)
        {
            for (unsigned int x = 0; x < width; x++)
            {
                if (tileGids[gid] != 0)
                    setMapTileId(layerCount, y, x, tileGids[gid]);
                gid++;
            }
        }
    }
}