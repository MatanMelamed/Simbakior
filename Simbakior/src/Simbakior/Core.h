#pragma once

#ifdef SM_PLATFORM_WINDOWS
#	ifdef SM_BUILD_DLL
#		define SIMBAKIOR_API __declspec(dllexport)
#	else
#		define SIMBAKIOR_API __declspec(dllimport)
#	endif
#else 
#	error Simbakior only supports Windows!
#endif

#ifdef SM_ENABLE_ASSERTS
#	define SM_ASSERT (x, ...) { if(!(x)) { SM_EEROR("Assertion Failed: {0}", __VA__ARGS__); __debugbreak(); } }
#	define SM_ASSERT (x, ...) { if(!(x)) { SM_EEROR("Assertion Failed: {0}", __VA__ARGS__); __debugbreak(); } }
#else
#	define SM_ASSERT(x, ...)
#	define SM_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
