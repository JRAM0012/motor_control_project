project "lib_glfw"
    targetdir "../lib"
    objdir "../obj"
    kind "StaticLib"
    files {
        "glfw/src/context.c",
        "glfw/src/init.c",
        "glfw/src/input.c",
        "glfw/src/monitor.c",
        "glfw/src/platform.c",
        "glfw/src/vulkan.c",
        "glfw/src/window.c",
        "glfw/src/egl_context.c",
        "glfw/src/osmesa_context.c",
        "glfw/src/null_init.c",
        "glfw/src/null_monitor.c",
        "glfw/src/null_window.c",
        "glfw/src/null_joystick.c",
        "glfw/src/win32_module.c",
        "glfw/src/win32_time.c",
        "glfw/src/win32_thread.c",
        "glfw/src/win32_init.c",
        "glfw/src/win32_joystick.c",
        "glfw/src/win32_monitor.c",
        "glfw/src/win32_window.c",
        "glfw/src/wgl_context.c",
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