workspace "Simbakior"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Simbakior/vendor/GLFW/include"

include "Simbakior/vendor/GLFW"

project "Simbakior"
	location "Simbakior"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "smpch.h"
	pchsource "Simbakior/src/smpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SM_PLATFORM_WINDOWS",
			"SM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SM_Release"
		symbols "On"

	filter "configurations:Dist"
		defines "SM_Dist"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Simbakior/vendor/spdlog/include",
		"Simbakior/src"
	}

	links
	{
		"Simbakior"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SM_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "SM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SM_Release"
		symbols "On"

	filter "configurations:Dist"
		defines "SM_Dist"
		symbols "On"
