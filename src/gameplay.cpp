#include "gameplay.h"

Gameplay::Gameplay(){
    this->pause = false;
    this->score = 0;
}

void Gameplay::render(){
    apple.render();
    snake.render();

    // checking if need to give score!
    if(snake.getX() == apple.getX() && snake.getY() == apple.getY()){
        score++;
        snake.addNewBody();

        apple.setNewPosition(snake.getX(), snake.getY());
    }

    if(snake.checkCollision()){
        snake.resetGame();
        apple.setNewPosition(snake.getX(), snake.getY());
        score = 0;
    }
}

void Gameplay::handleEvents(SDL_Event& e){
    switch(e.key.keysym.sym){
        case SDLK_UP: snake.setNewDirection(NORTH); break;
        case SDLK_DOWN: snake.setNewDirection(SOUTH); break;
        case SDLK_LEFT: snake.setNewDirection(WEST); break;
        case SDLK_RIGHT: snake.setNewDirection(EAST); break;
    }
}

int Gameplay::getScore(){
    return score;
}

bool Gameplay::isPaused(){
    return pause;
}

