project "lib_imgui"
    targetdir "../lib"
    objdir "../obj"
    kind "StaticLib"
    files { "imgui/*.cpp",
            "imgui/backends/imgui_impl_glut.cpp",
            "imgui/backends/imgui_impl_glfw.cpp",
            "imgui/backends/imgui_impl_opengl2.cpp", }
    includedirs { "imgui/", "glfw/include", "freeglut-3.4.0/include" }

    filter "configurations:Debug"
        defines { "MODE_DEBUG" }
        symbols "On"
        
    filter "configurations:Release"
        defines { "MODE_RELEASE" }
        optimize "On"