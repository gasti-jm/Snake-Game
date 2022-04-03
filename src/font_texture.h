#ifndef FONT_TEXTURE_H_INCLUDED
#define FONT_TEXTURE_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "renderer.h"

class FTexture{
    private:
		SDL_Texture* mTexture;
		int mWidth;
		int mHeight;

	public:
		FTexture();
		~FTexture();

		bool loadFromRenderedText(char textureText, SDL_Color textColor);
		void free();
		void render(int x, int y);
		int getWidth();
		int getHeight();
};

#endif
