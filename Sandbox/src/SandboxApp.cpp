#include "Simbakior.h"

class ExampleLayer : public Simbakior::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		SM_INFO("EampleLayer:Update");
	}

	void OnEvent(Simbakior::Event& event) override
	{
		SM_TRACE("{0}", event);
	}
};

class Sandbox : public Simbakior::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Simbakior::Application* Simbakior::CreateApplication() {
	return new Sandbox();
}