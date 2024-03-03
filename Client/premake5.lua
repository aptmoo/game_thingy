project "Client"
    kind "ConsoleApp"
    language "C"
    cdialect "C17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/")
    objdir ("%{wks.location}/bin-int/%{prj.name}")

    files
    {
        "src/**.h", "src/**.c"
    }

    includedirs
    {
        "src/",

        "%{wks.location}/Shared/src",
    }

    libdirs
    {
        "%{wks.location}/lib/",
    }

    links
    {
        "Shared",
    }

    defines
    {
    }

    filter "system:windows"
        systemversion "latest"
        defines { "PLATFORM_WINDOWS" }

    filter "system:linux"
        defines { "PLATFORM_LINUX" }
        libdirs { "/usr/lib", "../lib", }
        links { "dl", "m", "pthread", }
        targetname "game.out"

    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"