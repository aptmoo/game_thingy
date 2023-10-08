project "Engine"
    -- Project config
    kind "ConsoleApp"
    language "C"
    cdialect "C17"

    -- Output
    targetdir   "%{wks.location}/bin/"
    objdir      "%{wks.location}/bin-int/"

    -- Input
    files 
    {
        "src/**.h",
        "src/**.c"
    }

    includedirs
    {
        "src/"
    }

    links
    {
        "GLFW",
        
    }

    -- Platform specific
    filter "system:linux"
        libdirs { "/usr/lib/", "%{wks.location}/lib/" }
        links { "m", "dl", "pthread" }
        defines { "PLATFORM_LINUX" }

    filter "system:windows"
        libdirs { "%{wks.location}/lib/" }

    -- Configs
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"