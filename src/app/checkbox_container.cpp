#include "checkbox_container.hpp"

CheckBoxContainer::CheckBoxContainer(int row, int col) : numRows(row), numCols(col)
{
    for (int i = 0; i < (row * col); i++)
    {
        boxes.push_back(std::make_unique<CheckboxImage>());
    }
}

void CheckBoxContainer::Render()
{
    for (int rows = 0; rows < numRows; rows++)
    {
        ImGui::Columns(numCols, nullptr, false);
        for (int cols = 0; cols < numCols; cols++)
        {
            boxes[rows * numCols + cols].get()->render(rows, cols, numCols);
            ImGui::NextColumn();
        }
    }
}