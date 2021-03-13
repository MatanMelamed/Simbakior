#pragma once

#ifdef SM_PLATFORM_WINDOWS

extern Simbakior::Application* Simbakior::CreateApplication();

int main(int argc, char** argv)
{
	Simbakior::Log::Init();
	SM_CORE_WARN("Initialized Logger.");
	int x = 5;
	SM_INFO("geko {0}",x);


	auto app = Simbakior::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif

