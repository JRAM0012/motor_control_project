#ifndef __IMGUI_IMAGE__
#define __IMGUI_IMAGE__
#include "imgui.h"
class Image
{
public:
    Image(const char *image_path);
    ImTextureID get_image_id();
    ImVec2 get_image_size();
    ~Image();
    unsigned int image_texture_id;
    int image_width, image_height;
};

#endif //__IMGUI_IMAGE__