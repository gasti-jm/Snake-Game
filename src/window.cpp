#include "window.h"

Window::Window() {
	window = NULL;
	mouseFocus = false;
	keyBoardFocus = false;
	minimized = false;
	width = 0;
	height = 0;
}

Window::~Window() {

}

bool Window::init() {
    width = CFG::SCREEN_WIDTH;
	height = CFG::SCREEN_HEIGHT;

	// Create window
	window = SDL_CreateWindow("Snake",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_SHOWN);

    if(CFG::FULLSCREEN) SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	if (window != NULL) {
		mouseFocus = true;
		keyBoardFocus = true;
	}

	return window != NULL;
}

void Window::close() {
	if (window != NULL) SDL_DestroyWindow(window);

	mouseFocus = false;
	keyBoardFocus = false;
	width = 0;
	height = 0;
}

SDL_Renderer* Window::createRender() {
    if(CFG::VSYNC){
        return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    } else {
        return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
}

void Window::handleWindowEvents(SDL_Event& e) {
	if (e.type == SDL_WINDOWEVENT) { // window event ocurred
		switch (e.window.event) { // what event?
			case SDL_WINDOWEVENT_ENTER: // Mouse entered window
				mouseFocus = true;
				break;

			case SDL_WINDOWEVENT_LEAVE: // Mouse left window
				mouseFocus = false;
				break;

			case SDL_WINDOWEVENT_FOCUS_GAINED: // Window has keyboard focus
				keyBoardFocus = true;
				break;

			case SDL_WINDOWEVENT_FOCUS_LOST: // Window lost keyboard focus
				keyBoardFocus = false;
				break;

			case SDL_WINDOWEVENT_MINIMIZED: // Window minimized
				minimized = true;
				break;

			case SDL_WINDOWEVENT_MAXIMIZED: // Window maxized
				minimized = false;
				break;

			case SDL_WINDOWEVENT_RESTORED: // Window restored
				minimized = false;
				break;
		}
	}
}


int Window::getWidth() {
	return width;
}

int Window::getHeight() {
	return height;
}

bool Window::hasMouseFocus() {
	return mouseFocus;
}

bool Window::hasKeyBoardFocus() {
	return keyBoardFocus;
}

bool Window::isMinimized() {
	return minimized;
}



