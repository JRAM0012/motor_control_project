#include "checkbox_container.hpp"

CheckBoxContainer::CheckBoxContainer(int row, int col) : numRows(row), numCols(col)
{
    for (int i = 0; i < (row * col); i++)
    {
        boxes.push_back(std::make_unique<CheckboxImage>());
    }

    TargetBlockSet1 = 0;
    TargetBlockRun1 = 0;
    TargetBlockSet2 = 0;
    TargetBlockRun2 = 0;
    TimeBlockSet1 = 0;
    TimeBlockRun1 = 0;
    TimeBlockSet2 = 0;
    TimeBlockRun2 = 0;
}

#define TextWithPos(text, pos)\
    ImGui::SetCursorPos(pos);\
    ImGui::Text(text)

#define InputIntWithPos(text, val, pos)\
    ImGui::SetCursorPos(pos);\
    ImGui::InputInt(text, val);

#define ButtonWithPos(text, pos, curpos)\
    ImGui::SetCursorPos(curpos);\
    ImGui::Button(text, pos)

void CheckBoxContainer::RenderSelectedBlocks() {
    ImGui::SetCursorPos(ImVec2(90, 90));
    ImGui::BeginChild(3, ImVec2(960, 422), true);

    for (int x = 0; x < (numRows * numCols); x++) {
        if (boxes[x].get()->checked)
            boxes[x].get()->render(numRows, numCols, numCols);
    }
    ImGui::EndChild();
}

void CheckBoxContainer::RenderTargetBlock()
{
    ImGui::SetCursorPos(ImVec2(10, 80));
    ImGui::BeginChild(2, ImVec2(500, 200), true);

    ImGui::SetCursorPos(ImVec2(70, 15));   ImGui::Text("Target Open");
    ImGui::SetCursorPos(ImVec2(280, 15));  ImGui::Text("Target Close");
    ImGui::SetCursorPos(ImVec2(30, 60));   ImGui::Text("SET1:");
    ImGui::SetCursorPos(ImVec2(30, 100));  ImGui::Text("RUN1:");
    ImGui::SetCursorPos(ImVec2(220, 60));  ImGui::Text("SET2:");
    ImGui::SetCursorPos(ImVec2(220, 100)); ImGui::Text("RUN2:");

    ImGui::PushItemWidth(80);

    ImGui::SetCursorPos(ImVec2(70, 60));   ImGui::InputInt("SET1", &TargetBlockSet1);;
    ImGui::SetCursorPos(ImVec2(70, 100));  ImGui::InputInt("RUN1", &TargetBlockRun1);;
    ImGui::SetCursorPos(ImVec2(250, 60));  ImGui::InputInt("SET2", &TargetBlockSet2);;
    ImGui::SetCursorPos(ImVec2(250, 100)); ImGui::InputInt("RUN2", &TargetBlockRun2);;

    ImGui::SetCursorPos(ImVec2(150, 150));
    if(ImGui::Button("START", ImVec2(70, 40))) {
        //comState = STARTED;
    }
    ImGui::SetCursorPos(ImVec2(250, 150));
    if(ImGui::Button("RUN", ImVec2(70, 40))) {
        //comState = RUNNING;
    }
    ImGui::SetCursorPos(ImVec2(350, 150));
    if(ImGui::Button("STOP", ImVec2(70, 40))) {
        //comState = STOPPED;
    }

    ImGui::PopItemWidth();

    ImGui::EndChild();

    if (TargetBlockRun1 < 0) TargetBlockRun1 = 0;
    if (TargetBlockRun2 < 0) TargetBlockRun2 = 0;
    if (TargetBlockSet1 < 0) TargetBlockSet1 = 0;
    if (TargetBlockSet2 < 0) TargetBlockSet2 = 0;
	if (TimeBlockSet1 < 0) TimeBlockSet1 = 0;
	if (TimeBlockRun1 < 0) TimeBlockRun1 = 0;
	if (TimeBlockSet2 < 0) TimeBlockSet2 = 0;
	if (TimeBlockRun2 < 0) TimeBlockRun2 = 0;
}

void CheckBoxContainer::RenderTimeBlock()
{
    ImGui::SetCursorPos(ImVec2(550, 80));
	ImGui::BeginChild(17, ImVec2(500, 200), true);

    ImGui::SetCursorPos(ImVec2(60, 13)); ImGui::Text("Forward Time");
    ImGui::SetCursorPos(ImVec2(343, 18)); ImGui::Text("Reverse Time");

    ImGui::PushItemWidth(80);
    ImGui::SetCursorPos(ImVec2(64, 50)); ImGui::InputInt("SET1", &TimeBlockSet1);;
    ImGui::SetCursorPos(ImVec2(301, 50)); ImGui::InputInt("SET2", &TimeBlockSet2);;
    ImGui::SetCursorPos(ImVec2(66, 100)); ImGui::InputInt("RUN1", &TimeBlockRun1);;
    ImGui::SetCursorPos(ImVec2(305, 100)); ImGui::InputInt("RUN2", &TimeBlockRun2);;
    ImGui::PopItemWidth();

    ImGui::EndChild();
}

void CheckBoxContainer::Render()
{
    RenderTargetBlock();
    RenderTimeBlock();
    ImGui::SetCursorPos(ImVec2(10, 300));
    ImGui::BeginChild(1, ImVec2(800, 400), true); //(1, ImVec2(486,356), true
    for (int rows = 0; rows < numRows; rows++)
    {
        ImGui::Columns(numCols, nullptr, false);
        for (int cols = 0; cols < numCols; cols++)
        {
            boxes[rows * numCols + cols].get()->render(rows, cols, numCols);
            ImGui::NextColumn();
        }
    }
    ImGui::NextColumn();
    if(ImGui::Button("Toggle", ImVec2(50, 20)))
    {
        for (int row = 0; row < numRows; row++)
        {
            for (int col = 0; col < numCols; col++)
            {
                boxes[row * numCols + col].get()->checked = !boxes[row * numCols + col].get()->checked;
            }
        }
    }
    ImGui::NextColumn();

    if (ImGui::Button("uncheck all", ImVec2(90, 20)))
    {
        for (int row = 0; row < numRows; row++)
        {
            for (int col = 0; col < numCols; col++)
            {
                boxes[row * numCols + col].get()->checked = false;
            }
        }
    }
    ImGui::NextColumn();

    if (ImGui::Button("check all", ImVec2(70, 20)))
    {
        for (int row = 0; row < numRows; row++)
        {
            for (int col = 0; col < numCols; col++)
            {
                boxes[row * numCols + col].get()->checked = true;
            }
        }
    }
    ImGui::EndChild();
}