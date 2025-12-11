#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"
#include <string>
#include <vector>

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

    private:
        std::vector<Tile> tiles;
        std::vector<Tile**> tileMapGrid;
        Renderer* renderer;
        
        unsigned int width;
        unsigned int height;

        float tileWidth;
        float tileHeight;

        unsigned int texture;

        float imageWidth;
        float imageHeight;

        float convertedPosX;
        float convertedPosY;

        std::string imagePath;
    };
}

#endif
