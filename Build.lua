-- premake5.lua
workspace "ThreeDays"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "App"
   
    filter "configurations:*"
        defines { 'SOLUTION_DIR="' .. os.getcwd() .. '"' }  -- or wks.location
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

include "Core/Build-Core.lua"
include "App/Build-App.lua"