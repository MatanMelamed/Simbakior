#include "smpch.h"
#include "Application.h"

#include "Simbakior/Events/ApplicationEvent.h"
#include "Simbakior/Log.h"

namespace Simbakior {

	Simbakior::Application::Application()
	{
	}

	Simbakior::Application::~Application()
	{
	}

	void Simbakior::Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SM_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SM_TRACE(e);
		}

		while (true);
	}
}


