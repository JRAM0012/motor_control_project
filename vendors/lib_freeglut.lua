project "lib_freeglut"
    targetdir "../lib"
    objdir "../obj"
    kind "StaticLib"
    files {
        "freeglut-3.4.0/src/fg_callbacks.c",
        "freeglut-3.4.0/src/fg_cursor.c",
        "freeglut-3.4.0/src/fg_display.c",
        "freeglut-3.4.0/src/fg_ext.c",
        "freeglut-3.4.0/src/fg_font_data.c",
        "freeglut-3.4.0/src/fg_gamemode.c",
        "freeglut-3.4.0/src/fg_geometry.c",
        "freeglut-3.4.0/src/fg_gl2.c",
        "freeglut-3.4.0/src/fg_init.c",
        "freeglut-3.4.0/src/fg_input_devices.c",
        "freeglut-3.4.0/src/fg_joystick.c",
        "freeglut-3.4.0/src/fg_main.c",
        "freeglut-3.4.0/src/fg_misc.c",
        "freeglut-3.4.0/src/fg_overlay.c",
        "freeglut-3.4.0/src/fg_spaceball.c",
        "freeglut-3.4.0/src/fg_state.c",
        "freeglut-3.4.0/src/fg_stroke_mono_roman.c",
        "freeglut-3.4.0/src/fg_stroke_roman.c",
        "freeglut-3.4.0/src/fg_structure.c",
        "freeglut-3.4.0/src/fg_teapot.c",
        "freeglut-3.4.0/src/fg_videoresize.c",
        "freeglut-3.4.0/src/fg_window.c",
        "freeglut-3.4.0/src/fg_font.c",
        "freeglut-3.4.0/src/fg_menu.c",
        "freeglut-3.4.0/src/mswin/fg_cursor_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_display_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_ext_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_gamemode_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_init_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_input_devices_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_joystick_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_main_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_menu_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_spaceball_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_state_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_structure_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_window_mswin.c",
        "freeglut-3.4.0/src/mswin/fg_cmap_mswin.c",
        "freeglut-3.4.0/src/util/xparsegeometry_repl.c",
    }

    includedirs "freeglut-3.4.0/include"

    defines { "FREEGLUT_STATIC", "_CRT_SECURE_NO_WARNINGS" }

    filter "configurations:Debug"
        defines { "MODE_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "MODE_RELEASE" }
        optimize "On"