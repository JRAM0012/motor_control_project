#ifndef __IMGUI_IMAGE__
#define __IMGUI_IMAGE__

class Image {
public:
    unsigned char* data;
    Image(const char* image_path);
    ~Image();
};


#endif //__IMGUI_IMAGE__