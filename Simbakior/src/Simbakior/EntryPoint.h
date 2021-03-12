#pragma once

#ifdef SM_PLATFORM_WINDOWS

extern Simbakior::Application* Simbakior::CreateApplication();

int main(int argc, char** argv)
{
	printf("Simbakior Engine\n");
	auto app = Simbakior::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif

