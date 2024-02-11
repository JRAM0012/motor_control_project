#include "checkbox_image.hpp"
#include <stdio.h>

CheckboxImage::CheckboxImage()
{
    image = new Image("assets/icon_small.png");
    checked = false;
}
void CheckboxImage::render(int row, int col, int numCols)
{
    ImGui::Image(image->get_image_id(), image->get_image_size());
    char label_id_buffer[24];
    snprintf(label_id_buffer, 24, "box%d", row * numCols + col);
    ImGui::Checkbox(label_id_buffer, &checked);
}

CheckboxImage::~CheckboxImage()
{
    delete image;
}