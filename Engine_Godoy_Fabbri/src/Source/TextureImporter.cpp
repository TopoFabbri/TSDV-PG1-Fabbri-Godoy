#include "TextureImporter.h"

#include <glew.h>

#include "Debug.h"
#include "gl/GL.h"
#include "stb_image.h"

ToToEng::TextureImporter::TextureImporter()
{
}

ToToEng::TextureImporter::~TextureImporter()
{
}

unsigned int ToToEng::TextureImporter::loadTexture(const char* filePath, const Filtering filtering)
{
    int width, height;
    return loadTexture(filePath, width, height, filtering);
}

unsigned int ToToEng::TextureImporter::loadTexture(const char* filePath, int& width, int& height, const Filtering filtering)
{
    unsigned int texture;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    switch (filtering)
    {
    case Nearest:
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        break;

    case Linear:
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        break;
    }

    int nrChannels;

    unsigned char* data = stbi_load(filePath, &width, &height, &nrChannels, 0);

    if (data)
    {
        if (nrChannels == 4)
        {
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
        }
        else if (nrChannels == 3)
        {
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
        }
        else if (nrChannels == 2)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }
        else if (nrChannels == 1)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_R, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }

        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        Debug::log("Failed to load texture");
    }
    stbi_image_free(data);

    return texture;
}
