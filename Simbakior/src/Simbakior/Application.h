#pragma once

#include "Core.h"

namespace Simbakior {

	class SIMBAKIOR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
};

