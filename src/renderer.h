#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>

class Render {
	public:
		static SDL_Renderer* renderer;
		static TTF_Font* fileFont;

		static bool initTTF();
};

#endif
