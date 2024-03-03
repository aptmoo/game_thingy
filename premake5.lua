workspace "HelloWorld"
    configurations { "Debug", "Release" }

group "Dependencies"
    include "Dependencies/buildGlfw.lua"
group ""

include "Shared"
include "Client"