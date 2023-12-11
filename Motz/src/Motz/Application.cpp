#include "Application.h"
#include "stdio.h"

namespace mz {

	Application::Application()
	{
		isRunning = true;
		window = Window::CreateWindow();
	}

	Application::~Application()
	{
		isRunning = false;
	}

	void Application::Run()
	{
		printf(" Engine running");
		while(!Window::WindowShouldClose(window))
		{
			window->SwapBuffers(window);
			window->PollEvents();
		}

		glfwTerminate();
	}
}
