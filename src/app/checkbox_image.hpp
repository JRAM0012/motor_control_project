#ifndef __CHECKBOX_IMAGE_HPP__
#define __CHECKBOX_IMAGE_HPP__

#include "image.hpp"

class CheckboxImage
{
public:
    Image *image;
    bool checked;
    CheckboxImage();
    void render(int row, int col, int numCols);
    ~CheckboxImage();
};

#endif //__CHECKBOX_IMAGE_HPP__