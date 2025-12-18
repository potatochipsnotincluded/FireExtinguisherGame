project "App"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++23"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp" }

   includedirs
   {
      "Source",

	  "../Vendor/RaylibInclude",
	  "../Core/Source"
   }

	links
	{
		"Core"
	}

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")
    libdirs
    {
        "../Vendor"
    }
   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

    filter "system:macosx"
		links
		{
			"raylib",
                    "Cocoa.framework",
        "IOKit.framework",
        "CoreVideo.framework",
        "CoreAudio.framework",
        "AudioToolbox.framework",
        "AudioUnit.framework",
        "OpenGL.framework"
		}

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"