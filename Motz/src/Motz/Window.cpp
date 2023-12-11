#include "Window.h"
#include <stdio.h>
#include <iostream>

namespace mz{
	
	// Static callback function definitions
	void Window::ErrorCallback(int error, const char* description) {
		fprintf(stderr, "Error: %s\n", description);
	}
	
	void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		printf("\nkey");;
	}

	void Window::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
		printf("\nMouse");
	}

	void Window::CursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
		glfwGetCursorPos(window, &xpos, &ypos);
		printf("%f , %f\n", xpos, ypos);
	}

	void Window::WindowCloseCallback(GLFWwindow* window)
	{	
		printf("\nWindow closed!");
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}


	Window::Window()
	{	
		if (!glfwInit())
		{
			printf("Failed GLFW init");
		}

		glfwSetErrorCallback(ErrorCallback);

		glfwWindow = glfwCreateWindow(640, 480, "My Title", NULL, NULL);

		if (!glfwWindow)
		{
			printf("Failed to create window");
		}

		glfwSetWindowCloseCallback(glfwWindow, WindowCloseCallback);
		glfwSetKeyCallback(glfwWindow, KeyCallback);
		glfwSetCursorPosCallback(glfwWindow, CursorPosCallback);
		glfwSetMouseButtonCallback(glfwWindow, MouseButtonCallback);

		glfwMakeContextCurrent(glfwWindow);
	}


	Window::~Window()
	{
		glfwTerminate();
	}

	Window* Window::CreateWindow()
	{
		return new Window;
	}

	bool Window::WindowShouldClose(Window* window)
	{
		return glfwWindowShouldClose(window->glfwWindow);
	}

	void Window::PollEvents() {
		glfwPollEvents();
	}

	void Window::SwapBuffers(Window* window) {
		glfwSwapBuffers(window->glfwWindow);
	}

	/*bool Window::RunWindow() {
		if (!glfwWindowShouldClose(glfwWindow))
		{	
			glfwSwapBuffers(glfwWindow);
			glfwPollEvents();
			return true;
		}
		else
		glfwTerminate();
		return false;
	}*/
}