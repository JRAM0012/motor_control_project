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
    void RenderTargetBlock();
    void RenderTimeBlock();
    std::vector<std::unique_ptr<CheckboxImage>> boxes;
    int numRows, numCols;
    int TargetBlockSet1, TargetBlockRun1,
        TargetBlockSet2, TargetBlockRun2;

    int TimeBlockSet1, TimeBlockRun1,
        TimeBlockSet2, TimeBlockRun2;
};

#endif //__CHECKBOX_CONTAINER__