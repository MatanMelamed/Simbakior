#include "Simbakior.h"

class Sandbox : public Simbakior::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Simbakior::Application* Simbakior::CreateApplication(){
	return new Sandbox();
}