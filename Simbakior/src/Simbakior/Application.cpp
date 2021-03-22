#include "smpch.h"
#include "Application.h"

#include "Simbakior/Events/ApplicationEvent.h"
#include "Simbakior/Log.h"

#include <GLFW/glfw3.h>

namespace Simbakior {

	Simbakior::Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Simbakior::Application::~Application()
	{
	}

	void Simbakior::Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}