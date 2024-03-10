workspace "HelloWorld"
    configurations { "Debug", "Release" }

newoption
{
    trigger = "refapi",
    value = "API",
    description = "Sets the rendering and windowing api",
    allowed = 
    {
        { "gl", "OpenGL and GLFW"},
    },
    default = "gl",
}

group "Dependencies"
    filter { "options:refapi=gl"}
        include "Dependencies/buildGlfw.lua"
group ""

include "Shared"
include "Client"