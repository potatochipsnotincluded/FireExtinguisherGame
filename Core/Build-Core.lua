project "Core"
   kind "StaticLib"
   language "C++"
   cppdialect "C++23"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp"}

   includedirs
   {
      "Source",
	 "../Vendor/RaylibInclude"
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { }
	   links
	   {
		  "../Vendor/raylibdll.lib",
		  "opengl32.lib",
		  "kernel32.lib",
		  "user32.lib",
		  "gdi32.lib",
		  "winmm.lib"
	   }
	   
	filter "system:macosx"
		links
		{
			"../Vendor/libraylib.a"
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