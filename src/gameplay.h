#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED

#include <SDL.h>

#include "drawn.h"
#include "fonts.h"
#include "apple.h"
#include "snake.h"

class Gameplay{
    private:
        Apple apple;
		Snake snake;
        bool pause;
        int score;

    public:
        Gameplay();

        void render();
        void handleEvents(SDL_Event&);

        int getScore();
        int getMenu();
        bool isPaused();
        bool inOptions();
        void setOptions();
};

#endif
