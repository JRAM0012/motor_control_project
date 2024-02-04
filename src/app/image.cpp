#include "image.hpp"
#include "glad.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Image::Image(const char *image_path)
{
    int channel;
    unsigned char* image_data = stbi_load(image_path, &image_width, &image_height, &channel, 0);

    if (!image_data)
    {
        printf("Error: Could not open %s\n", image_path);
        exit(-1);
    }
    else
    {
        printf("Success: loaded image (%dx%d) with %d channels", image_width, image_height, channel);
    }
    glGenTextures(1, &image_texture_id);
    glBindTexture(GL_TEXTURE_2D, image_texture_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (image_data)
    {
        if (channel == 4)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
        }
        else if (channel == 3)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_width, image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
        }
        else
        {
            printf("error: texture has unsupported channel size: %d", channel);
        }
    }

    stbi_image_free(image_data);
}

ImTextureID Image::get_image_id()
{
    return reinterpret_cast<ImTextureID>(static_cast<uintptr_t>(image_texture_id));
}

ImVec2 Image::get_image_size()
{
    return ImVec2(static_cast<float>(image_width), static_cast<float>(image_height));
}

Image::~Image()
{
    glDeleteTextures(1, &image_texture_id);
}