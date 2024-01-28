workspace "project-workspace"
    architecture "x32"
    configurations { "Debug", "Release" }

project "lib_freeglut"
    targetdir "lib"
    kind "StaticLib"
    files {
        "vendors/freeglut-3.4.0/src/fg_callbacks.c",
        "vendors/freeglut-3.4.0/src/fg_cursor.c",
        "vendors/freeglut-3.4.0/src/fg_display.c",
        "vendors/freeglut-3.4.0/src/fg_ext.c",
        "vendors/freeglut-3.4.0/src/fg_font_data.c",
        "vendors/freeglut-3.4.0/src/fg_gamemode.c",
        "vendors/freeglut-3.4.0/src/fg_geometry.c",
        "vendors/freeglut-3.4.0/src/fg_gl2.c",
        "vendors/freeglut-3.4.0/src/fg_init.c",
        "vendors/freeglut-3.4.0/src/fg_input_devices.c",
        "vendors/freeglut-3.4.0/src/fg_joystick.c",
        "vendors/freeglut-3.4.0/src/fg_main.c",
        "vendors/freeglut-3.4.0/src/fg_misc.c",
        "vendors/freeglut-3.4.0/src/fg_overlay.c",
        "vendors/freeglut-3.4.0/src/fg_spaceball.c",
        "vendors/freeglut-3.4.0/src/fg_state.c",
        "vendors/freeglut-3.4.0/src/fg_stroke_mono_roman.c",
        "vendors/freeglut-3.4.0/src/fg_stroke_roman.c",
        "vendors/freeglut-3.4.0/src/fg_structure.c",
        "vendors/freeglut-3.4.0/src/fg_teapot.c",
        "vendors/freeglut-3.4.0/src/fg_videoresize.c",
        "vendors/freeglut-3.4.0/src/fg_window.c",
        "vendors/freeglut-3.4.0/src/fg_font.c",
        "vendors/freeglut-3.4.0/src/fg_menu.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_cursor_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_display_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_ext_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_gamemode_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_init_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_input_devices_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_joystick_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_main_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_menu_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_spaceball_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_state_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_structure_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_window_mswin.c",
        "vendors/freeglut-3.4.0/src/mswin/fg_cmap_mswin.c",
        "vendors/freeglut-3.4.0/src/util/xparsegeometry_repl.c",
    }

    includedirs "vendors/freeglut-3.4.0/include"

    defines { "FREEGLUT_STATIC", "_CRT_SECURE_NO_WARNINGS" }

    filter "configurations:Debug"
        defines { "MODE_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "MODE_RELEASE" }
        optimize "On"


project "lib_glfw"
    targetdir "lib"
    kind "StaticLib"
    files {
        "vendors/glfw/src/context.c",
        "vendors/glfw/src/init.c",
        "vendors/glfw/src/input.c",
        "vendors/glfw/src/monitor.c",
        "vendors/glfw/src/platform.c",
        "vendors/glfw/src/vulkan.c",
        "vendors/glfw/src/window.c",
        "vendors/glfw/src/egl_context.c",
        "vendors/glfw/src/osmesa_context.c",
        "vendors/glfw/src/null_init.c",
        "vendors/glfw/src/null_monitor.c",
        "vendors/glfw/src/null_window.c",
        "vendors/glfw/src/null_joystick.c",
        "vendors/glfw/src/win32_module.c",
        "vendors/glfw/src/win32_time.c",
        "vendors/glfw/src/win32_thread.c",
        "vendors/glfw/src/win32_init.c",
        "vendors/glfw/src/win32_joystick.c",
        "vendors/glfw/src/win32_monitor.c",
        "vendors/glfw/src/win32_window.c",
        "vendors/glfw/src/wgl_context.c",
    }

    defines {
        "WIN32",
        "_WINDOWS",
        "_GLFW_WIN32",
        "UNICODE",
        "_UNICODE",
        "_CRT_SECURE_NO_WARNINGS",
    }

    filter "configurations:Debug"
        defines { "MODE_DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "MODE_RELEASE" }
        optimize "On"

project "lib_imgui"
    targetdir "lib"
    kind "StaticLib"
    files { "vendors/imgui/*.cpp",
            "vendors/imgui/backends/imgui_impl_glut.cpp",
            "vendors/imgui/backends/imgui_impl_glfw.cpp",
            "vendors/imgui/backends/imgui_impl_opengl2.cpp", }
    includedirs { "vendors/imgui/", "vendors/glfw/include", "vendors/freeglut-3.4.0/include" }

    filter "configurations:Debug"
        defines { "MODE_DEBUG" }
        symbols "On"
        
    filter "configurations:Release"
        defines { "MODE_RELEASE" }
        optimize "On"
            
project "project_application"
    targetdir "bin"
    language "C++"
    kind "ConsoleApp"
    files { "src/**.cpp", }
    links { "lib_freeglut", "lib_glfw", "lib_imgui", "opengl32", "gdi32" }
    includedirs { "include", "vendors/imgui/", "vendors/imgui/backends", "vendors/glfw/include", }

    filter "configurations:Debug"
        defines { "MODE_DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "MODE_RELEASE" }
        optimize "On"
        
    filter "system:windows"
        files { "assets/icon.ico" }
        buildoptions { "/FR" }
        files { "assets/resources.rc" }