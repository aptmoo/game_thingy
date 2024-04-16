project "Shared"
    kind "StaticLib"
    language "C"
    cdialect "C17"
    staticruntime "off"

    targetdir ("%{wks.location}/lib/")
    objdir ("%{wks.location}/bin-int/%{prj.name}")

    files 
    {
        "./shared/**.h", "./shared/**.c",
    }

    includedirs
    {
        "./shared/"
    }

    links
    {
        
    }

    defines
    {
        
    }

    filter "system:windows"
        systemversion "latest"
        defines { }

    filter "system:linux"
        defines { }
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