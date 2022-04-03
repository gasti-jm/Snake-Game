#include <iostream>
#include "engine.h"

int main(int argc, char* args[]) {
	Engine engine;
	if (engine.init()) engine.mainLoop();
	engine.close();
	return 0;
}
