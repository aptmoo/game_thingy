project "GLFW"
    kind "StaticLib"
    language "C"
    staticruntime "off"

    files 
    {
        "glfw/src/**.c", "glfw/src/**.h",
        "glfw/include/**.h"
    }

    includedirs
    {
        "./",
        "glfw/include/",
    }

    links
    {
        
    }

    defines
    {
        
    }

    targetdir ("%{wks.location}/lib/")
    objdir ("%{wks.location}/Intermediates/%{prj.name}")

    filter "system:windows"
        systemversion "latest"
        defines { "_GLFW_WIN32" }

    filter "system:linux"
        defines { "_GLFW_X11" }
        libdirs { "/usr/lib", }
        links { "dl", "m", "pthread" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"