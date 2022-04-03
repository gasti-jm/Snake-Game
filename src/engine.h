#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <iostream>
#include <sstream>

#include <SDL.h>
#include <SDL_ttf.h>

#include "renderer.h"
#include "window.h"
#include "fonts.h"
#include "timer.h"
#include "gameplay.h"

class Engine {
	private:
	    bool isRunning;
		Window window;
		SDL_Event e;
		Fonts font;

		Timer fpsTimer;
		Uint32 countedFrames = 0;
		Uint32 FPS = 0;
		Gameplay gameplay;

	public:
		Engine();

		bool init();
		void close();

		void renderScreen();
		void UpdateFPS();

		void renderPrincipalMenu();
        void renderPause();

		void mainLoop();
		void checkEvents();
};

#endif
