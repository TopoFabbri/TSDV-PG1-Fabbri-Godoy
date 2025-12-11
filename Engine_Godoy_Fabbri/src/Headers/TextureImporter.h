#pragma once
#include "Exports.h"

namespace ToToEng
{
    class TOTO_API TextureImporter
    {
    public:
        TextureImporter();
        ~TextureImporter();

        static unsigned int loadTexture(const char* filePath);
        static unsigned int loadTexture(const char* filePath, int& width, int& height);
    };
}
