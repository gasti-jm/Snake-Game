#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SDL.h>
#include "cfg.h"
#include "renderer.h"

class Window {
	private:
		SDL_Window* window; // window data.
		int width, height; // window dimentions.
		bool mouseFocus, keyBoardFocus, minimized; // window focus

	public:
		Window();
		~Window();

		bool init();
		void close();

		SDL_Renderer* createRender(); // create render from internal window.
		void handleWindowEvents(SDL_Event&);

		int getWidth();
		int getHeight();

		bool hasMouseFocus();
		bool hasKeyBoardFocus();
		bool isMinimized();
};

#endif
