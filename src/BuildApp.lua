project "App"
    kind "ConsoleApp"
    language "C"
    cdialect "C17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/")
    objdir ("%{wks.location}/bin-int/%{prj.name}")

    files 
    {
        "./app/**.h", "./app/**.c",
        "./platform/**.h",
    }

    filter "system:windows"
        files { "./platform/windows/**.c" }

    filter "system:linux"
        files { "./platform/nix/**.c" }

    includedirs
    {
        "./",
        "./app/"
    }

    links
    {
        "Shared"
    }

    defines
    {
        
    }

    filter "system:windows"
        systemversion "latest"
        defines { }

    filter "system:linux"
        defines {  }
        libdirs { "/usr/lib", "%{wks.location}/lib/" }
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