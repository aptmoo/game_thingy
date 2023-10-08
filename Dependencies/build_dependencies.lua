project "GLFW"
    -- Project config
    kind "StaticLib"
    language "C"

    -- Output
    targetdir   "%{wks.location}/lib/"
    objdir      "%{wks.location}/bin-int/"

    -- Input
    files 
    {
        "glfw/**.h",
        "glfw/src/**.c"
    }

    includedirs
    {
        "glfw/include",
        "glfw/src"
    }

    links
    {

    }

    -- Platform specific
    filter "system:linux"
        libdirs { "/usr/lib/", "%{wks.location}/lib/" }
        links { "m", "dl", "pthread", "X11", "Xi", "Xrandr" }
        defines { "_GLFW_X11" }

    filter "system:windows"
        libdirs { "%{wks.location}/lib/" }

    -- Configs
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"