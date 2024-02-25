#include "checkbox_image.hpp"
#include <stdio.h>

CheckboxImage::CheckboxImage()
{
    closeImage   = new Image("assets/close_image.png");
    openImage    = new Image("assets/open_image.png");
    forwardImage = new Image("assets/forward_image.png");
    reverseImage = new Image("assets/reverse_image.png");
    checked = false;
    state = STATE_OPEN;
}
void CheckboxImage::render(int row, int col, int numCols)
{

    ImTextureID imageId;
    ImVec2 imageSize;
    switch (state)
    {
    case STATE_CLOSED:
    {
        imageId = closeImage->get_image_id();
        imageSize = closeImage->get_image_size();
    }
    break;
    case STATE_OPEN:
    {
        imageId = openImage->get_image_id();
        imageSize = openImage->get_image_size();
    }
    break;
    case STATE_FORWARD:
    {
        imageId = forwardImage->get_image_id();
        imageSize = forwardImage->get_image_size();
    }
    break;
    case STATE_REVERSE:
    {
        imageId = reverseImage->get_image_id();
        imageSize = reverseImage->get_image_size();
    }
    break;
    default:
        printf("Error in Switch statement %s:%d", __FILE__, __LINE__);
        break;
    }
    ImGui::Image(imageId, imageSize);
    char label_id_buffer[24];
    snprintf(label_id_buffer, 24, "box%d", row * numCols + col);
    ImGui::Checkbox(label_id_buffer, &checked);
}

CheckboxImage::~CheckboxImage()
{
    delete closeImage;
    delete openImage;
    delete forwardImage;
    delete reverseImage;
}