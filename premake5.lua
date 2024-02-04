workspace "project-workspace"
    architecture "x32"
    configurations { "Debug", "Release" }

include "src/motorcontroll.lua"

group "libraries"
    include "vendors/lib_imgui.lua"
    include "vendors/lib_glfw.lua"
    include "vendors/lib_freeglut.lua"