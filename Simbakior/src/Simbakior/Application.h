#pragma once

#include "Core.h"

#include "Window.h"
#include "Simbakior/LayerStack.h"
#include "Simbakior/Events/Event.h"
#include "Simbakior/Events/ApplicationEvent.h"


namespace Simbakior {

	class SIMBAKIOR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		LayerStack m_LayerStack;
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in client
	Application* CreateApplication();
};

