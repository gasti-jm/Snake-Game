#ifndef DRAWN_H_INCLUDED
#define DRAWN_H_INCLUDED

#include <SDL.h>
#include "renderer.h"

class Drawn{
    public:
        static void drawQuad(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool line = false){
            SDL_Rect RECT = { x, y, w, h };
            SDL_SetRenderDrawColor(Render::renderer, r, g, b, a);

            if (line){
                SDL_RenderDrawRect(Render::renderer, &RECT);
            } else {
                SDL_RenderFillRect(Render::renderer, &RECT);
            }
        }


        static void drawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
            SDL_SetRenderDrawColor(Render::renderer, r, g, b, a);
            SDL_RenderDrawLine(Render::renderer, x1, y1, x2, y2);
        }
};

#endif
