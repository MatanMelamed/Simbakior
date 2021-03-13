#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
 
namespace Simbakior {

	class SIMBAKIOR_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};


}

// Core log macros
#define SM_CORE_TRACE(...)    ::Simbakior::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SM_CORE_INFO(...)     ::Simbakior::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SM_CORE_WARN(...)     ::Simbakior::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SM_CORE_ERROR(...)    ::Simbakior::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SM_CORE_FATAL(...)    ::Simbakior::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SM_TRACE(...)         ::Simbakior::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SM_INFO(...)          ::Simbakior::Log::GetClientLogger()->info(__VA_ARGS__)
#define SM_WARN(...)          ::Simbakior::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SM_ERROR(...)         ::Simbakior::Log::GetClientLogger()->error(__VA_ARGS__)
#define SM_FATAL(...)         ::Simbakior::Log::GetClientLogger()->fatal(__VA_ARGS__)

// the logs are defined in macros so in a dist build 
// we can strip them up simply by defining them to noting:
// #define SM_CORE_INFO