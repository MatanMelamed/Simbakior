#include "smpch.h"
#include "Application.h"

#include "Simbakior/Log.h"

#include <GLFW/glfw3.h>

namespace Simbakior {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Simbakior::Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCalllback(BIND_EVENT_FN(OnEvent));
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

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispacther(e);
		dispacther.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		SM_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}
	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}