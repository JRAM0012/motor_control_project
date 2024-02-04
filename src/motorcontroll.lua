project "app"
    targetdir "../bin"
    objdir "../obj"
    language "C++"
    kind "ConsoleApp"
    files { "app/**.cpp", }
    links { "lib_freeglut", "lib_glfw", "lib_imgui", "opengl32", "gdi32" }
    includedirs { "include", "../vendors/imgui/", "../vendors/imgui/backends", "../vendors/glfw/include", "../vendors/stb" }

    filter "configurations:Debug"
        debugdir "../bin"
        defines { "MODE_DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        debugdir "../bin"
        defines { "MODE_RELEASE" }

        optimize "On"
        
    filter "system:windows"
        files { "../bin/assets/icon.ico" }
        buildoptions { "/FR" }
        files { "../bin/assets/resources.rc" }