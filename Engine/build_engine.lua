project "Engine"
    -- Language
    language "C++"
    cppdialect "C++17"

    -- Output
    kind        "ConsoleApp"
    targetdir   "%{wks.location}/bin/"
    objdir      "%{wks.location}/bin-int/"

    files
    {
        "src/**.h", "src/**.cpp"
    }

    links
    {
        "glfw",
        "raylib",
        "GL"
    }

    includedirs
    {
        "./",
        "src/",

        "%{wks.location}/Dependencies/raylib-cpp/include/",
        "%{wks.location}/Dependencies/entt/",
    }

    -- Platform
    filter "system:linux"
        libdirs { "/usr/lib/", "%{wks.location}/lib/" }
        links { "m", "dl", "pthread" }
        defines { "PLATFORM_LINUX" }
    
    -- Configs
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"