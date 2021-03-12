#pragma once

#ifdef SM_PLATFORM_WINDOWS
	#ifdef SM_BUILD_DLL
		#define SIMBAKIOR_API __declspec(dllexport)
	#else
		#define SIMBAKIOR_API __declspec(dllimport)
	#endif
#else 
	#error Simbakior only supports Windows!
#endif
