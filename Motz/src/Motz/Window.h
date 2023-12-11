#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


namespace mz {
	class Window
	{
		public:
			Window();
			~Window();
			static Window* CreateWindow();
			static bool WindowShouldClose(Window* window);

			void SwapBuffers(Window* window);
			void PollEvents();
			

		private:
			GLFWwindow* glfwWindow;
			static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
			static void CursorPosCallback(GLFWwindow* window, double xpos, double ypos);
			static void ErrorCallback(int error, const char* description);
			static void WindowCloseCallback(GLFWwindow* window);

		};

}
