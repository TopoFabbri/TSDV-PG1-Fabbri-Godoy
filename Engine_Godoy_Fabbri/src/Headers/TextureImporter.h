#pragma once
#include "Exports.h"

namespace ToToEng
{
    class TOTO_API TextureImporter
    {
    public:
        enum Filtering
        {
            Nearest, 
            Linear
        };
        
        TextureImporter();
        ~TextureImporter();

        static unsigned int loadTexture(const char* filePath, Filtering filtering = Nearest);
        static unsigned int loadTexture(const char* filePath, int& width, int& height, Filtering filtering = Nearest);
    };
}
