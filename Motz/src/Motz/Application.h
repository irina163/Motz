#pragma once
#include "Window.h"
#include <GLFW/glfw3.h>

namespace mz {

	class Application
	{
	private:
		bool isRunning;
		Window* window;
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* Create_Application();

}
