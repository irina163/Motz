#include "Motz.h"
#include "stdio.h"

//The game class is a type of game engine application
class Boat : public mz::Application
{
public:
	Boat()
	{
		int mesh[] = { 0, 1, 2 };
	}

	~Boat()
	{

	}

};
mz::Application* mz::Create_Application()
{	
	printf("Boat created  \n");
	return new Boat();
}