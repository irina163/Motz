#pragma once
#include "stdio.h"
#include "Application.h"


extern mz::Application* mz::Create_Application();

int main(int argc, char** argv) {

	printf(" Hello\n ");

	//Create game application
	auto app = mz::Create_Application();

	//Run game application inside the engine
	app->Run();
	printf(" Finished running boat  \n");

	delete app;
}