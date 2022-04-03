#include "font_texture.h"

FTexture::FTexture(){
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

FTexture::~FTexture(){
	free();
}

void FTexture::free(){
	if(mTexture != NULL){
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void FTexture::render(int x, int y){
	SDL_Rect renderQuad = {x, y, mWidth, mHeight}; // Set rendering space and render to screen

	// Render to screen
	SDL_RenderCopyEx(Render::renderer, mTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}

int FTexture::getWidth(){
	return mWidth;
}

int FTexture::getHeight(){
	return mHeight;
}

bool FTexture::loadFromRenderedText(char textureText, SDL_Color textColor){
    free();
    std::string letterInString(1, textureText);

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(Render::fileFont, letterInString.c_str(), textColor);

    if(textSurface == NULL){
        std::cout << "Unable to render text surface! ERROR CODE: " << TTF_GetError() << std::endl;
    } else {
        mTexture = SDL_CreateTextureFromSurface(Render::renderer, textSurface);

        if(mTexture == NULL){
            std::cout << "Unable to create texture from rendered text! ERROR CODE: " << SDL_GetError() << std::endl;
        } else {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        SDL_FreeSurface(textSurface);
    }

    return mTexture != NULL;
}
