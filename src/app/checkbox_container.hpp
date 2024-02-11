#ifndef __CHECKBOX_CONTAINER__
#define __CHECKBOX_CONTAINER__

#include <vector>
#include <memory>
#include "checkbox_image.hpp"

class CheckBoxContainer
{
public:
    CheckBoxContainer(int row, int col);
    void Render();
    std::vector<std::unique_ptr<CheckboxImage>> boxes;
    int numRows, numCols;
};

#endif //__CHECKBOX_CONTAINER__