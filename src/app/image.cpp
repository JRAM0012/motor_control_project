#include "image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Image::Image(const char *image_path)
{
    int width, height, bits_per_pixel;
    data = stbi_load(image_path, &width, &height, &bits_per_pixel, 0);
    char noErrors = 1;

    if (!data)
    {
        printf("Error: Could not open %s\n", image_path);
        noErrors = -1;
    }
    else
    {
        printf("Success: loaded image");
    }
}



Image::~Image() {
    stbi_image_free(data);
}