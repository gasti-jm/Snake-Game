#include "renderer.h"

SDL_Renderer* Render::renderer = NULL;
TTF_Font* Render::fileFont = NULL;

bool Render::initTTF(){
    fileFont = TTF_OpenFont("resources/font/ARCADE.ttf", 16);
    if(fileFont == NULL) return false;

    return true;
}
