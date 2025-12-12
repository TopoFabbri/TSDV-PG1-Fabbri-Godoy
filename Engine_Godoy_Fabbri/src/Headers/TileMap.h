#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include <string>
#include <vector>

#include "tinyxml2.h"

namespace ToToEng
{
    class TOTO_API TileMap
    {
    public:
        explicit TileMap(Renderer* renderer);
        ~TileMap();

        const Tile& tile(unsigned int uiId);
        void setTile(const Tile& rkTile);
        void setMapTileId(int layer, unsigned int uiCol, unsigned int uiRow, unsigned int uiId);

        void setDimensions(float width, float height);
        void setTileDimensions(float tileWidth, float tileHeight);

        void setTexture(unsigned int texture);
        void draw() const;

        bool importTileMap(std::string filePath);
        tinyxml2::XMLElement* handleImportMapAttributes(tinyxml2::XMLDocument& doc);
        tinyxml2::XMLElement* handleImportTileset(tinyxml2::XMLElement* mapNode);
        void handleImportTiles(tinyxml2::XMLElement* pTileset);
        bool handleImportMapData(tinyxml2::XMLElement*& pLayer);
        
        void initializeLayer(int layerCount);
        void handleCsvTileImport(tinyxml2::XMLElement* pData, std::vector<int>& tileGids);
        void handleEmbeddedTileImport(tinyxml2::XMLElement* pData, std::vector<int> tileGids);
        void setTiles(int layerCount, std::vector<int> tileGids);

    private:
        std::vector<Tile> tiles;
        std::vector<Tile**> tileMapGrid;
        Renderer* renderer;
        
        unsigned int width;
        unsigned int height;

        float tileWidth;
        float tileHeight;

        unsigned int texture;

        int imageWidth;
        int imageHeight;

        float convertedPosX;
        float convertedPosY;

        std::string imagePath;
    };
}

#endif
