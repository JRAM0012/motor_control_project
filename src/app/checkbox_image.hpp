#ifndef __CHECKBOX_IMAGE_HPP__
#define __CHECKBOX_IMAGE_HPP__

#include "image.hpp"

typedef enum MOTOR_STATE {
    STATE_CLOSED = 0,
    STATE_OPEN,
    STATE_FORWARD,
    STATE_REVERSE,
}MOTOR_STATE;

class CheckboxImage
{
public:
    Image *closeImage;
    Image *openImage;
    Image *forwardImage;
    Image* reverseImage;
    bool checked;
    MOTOR_STATE state;
    CheckboxImage();
    void render(int row, int col, int numCols);
    ~CheckboxImage();
};

#endif //__CHECKBOX_IMAGE_HPP__