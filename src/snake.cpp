#include "snake.h"
#include <iostream>

Snake::Snake(){
    updateSnake.start(); // init timer..

    // head.
    parts[0].tileX = (CFG::SCREEN_WIDTH / 2) / 16;
    parts[0].tileY = (CFG::SCREEN_HEIGHT / 2) / 16;
    parts[0].direction = EAST; // default in any snake game.
    parts[0].tileChangeDirecX = NONE;
    parts[0].tileChangeDirecY = NONE;
    parts[0].visible = true;

    // body
    for(int i = 1; i < MAX_LENGTH_SNAKE; i++){
        parts[i].tileX = parts[i - 1].tileX - 1;
        parts[i].tileY = parts[i - 1].tileY;
        parts[i].tileChangeDirecX = NONE;
        parts[i].tileChangeDirecY = NONE;
        parts[i].direction = EAST;
        parts[i].visible = false;
    }
}

void Snake::updatePos(int i){
    if(!parts[i].visible) return;

    switch(parts[i].direction){
        case NORTH:
            parts[i].tileY--; // update pos
            if(parts[i].tileY < 0) parts[i].tileY = (CFG::SCREEN_HEIGHT / 16) - 1;
            break;

        case SOUTH:
            parts[i].tileY++;
            if(parts[i].tileY > (CFG::SCREEN_HEIGHT / 16) - 1)  parts[i].tileY = 0;
            break;

        case EAST:
            parts[i].tileX++;
            if(parts[i].tileX > (CFG::SCREEN_WIDTH / 16) - 1) parts[i].tileX = 0;
            break;

        case WEST:
            parts[i].tileX--;
            if(parts[i].tileX < 0) parts[i].tileX = (CFG::SCREEN_WIDTH / 16) - 1;
            break;
    }
}

void Snake::render(){
    // update positions...
    if(SDL_GetTicks() >= updateSnake.getTicks() - 50){
        for(int i = 0; i < MAX_LENGTH_SNAKE; i++) updatePos(i);
        updateSnake.start(); // update timer
    }

    // draw snake!
    for(int i = 0; i < MAX_LENGTH_SNAKE; i++){
        if(parts[i].visible){
            Drawn::drawQuad(parts[i].tileX * 16,
                            parts[i].tileY * 16,
                            snakePixelSize, snakePixelSize,
                            255, 255, 255, 255);

            accommodateSnake(i);
        }
    }
}

bool Snake::checkCollision(){
    for(int i = 1; i < MAX_LENGTH_SNAKE; i++){
        if(parts[i].visible){
            if(parts[0].tileX == parts[i].tileX && parts[0].tileY == parts[i].tileY)
                return true;
        }
    }
    return false;
}

void Snake::resetGame(){
    parts[0].tileX = (CFG::SCREEN_WIDTH / 2) / 16;
    parts[0].tileY = (CFG::SCREEN_HEIGHT / 2) / 16;
    parts[0].direction = EAST; // default in any snake game.
    parts[0].tileChangeDirecX = NONE;
    parts[0].tileChangeDirecY = NONE;
    parts[0].visible = true;

    for(int i = 1; i < MAX_LENGTH_SNAKE; i++){
        parts[i].tileX = parts[i - 1].tileX - 1;
        parts[i].tileY = parts[i - 1].tileY;
        parts[i].tileChangeDirecX = NONE;
        parts[i].tileChangeDirecY = NONE;
        parts[i].direction = EAST;
        parts[i].visible = false;
    }
}

void Snake::accommodateSnake(int i){
    if(parts[i].tileY == parts[i].tileChangeDirecY &&
        parts[i].tileX == parts[i].tileChangeDirecX){

        // avisale al siguente que tambien tiene que cambiar en esta posicion.
        if ((i+1) < MAX_LENGTH_SNAKE){
            if(parts[i+1].visible){
                updateDirection(i+1); // acomodalo atras del que se actualizo
                parts[i+1].direction = parts[i].direction;
                parts[i+1].tileChangeDirecX = parts[i].tileChangeDirecX;
                parts[i+1].tileChangeDirecY = parts[i].tileChangeDirecY;
            }
        }

        // yo ya no tengo otro objetivo.
        parts[i].tileChangeDirecX = NONE;
        parts[i].tileChangeDirecY = NONE;

        updateDirection(i);
    }
}

void Snake::setNewDirection(int newDirection){
    if(parts[1].visible){
        if(!checkDirection(newDirection)) return;
        parts[1].tileChangeDirecX = parts[0].tileX;
        parts[1].tileChangeDirecY = parts[0].tileY;
    }

    parts[0].direction = newDirection;
}

bool Snake::checkDirection(int newDirection){
    int contraryDirection = 0;

    // set contrary direction.
    switch(newDirection){
        case NORTH: contraryDirection = SOUTH; break;
        case SOUTH: contraryDirection = NORTH; break;
        case EAST: contraryDirection = WEST; break;
        case WEST: contraryDirection = EAST; break;
    };

    // you can't go to the contrary direction
    if (parts[1].direction == contraryDirection) return false;
    return true;
}

void Snake::updateDirection(int i){
    if(i == 0) return; // no.

    parts[i].direction = parts[i-1].direction;

    switch(parts[i-1].direction){
        case NORTH:
            parts[i].tileX = parts[i-1].tileX;
            parts[i].tileY = parts[i-1].tileY + 1;
            break;

        case SOUTH:
            parts[i].tileX = parts[i-1].tileX;
            parts[i].tileY = parts[i-1].tileY - 1;
            break;

        case EAST:
            parts[i].tileY = parts[i-1].tileY;
            parts[i].tileX = parts[i-1].tileX - 1;
            break;

        case WEST:
            parts[i].tileY = parts[i-1].tileY;
            parts[i].tileX = parts[i-1].tileX + 1;
            break;
    }
}

void Snake::addNewBody(){
    int i = 0;
    while(parts[i].visible && i < MAX_LENGTH_SNAKE) i++; // get last parts not created!

    if(i == MAX_LENGTH_SNAKE) return; // it's the last?

    if(!parts[i].visible){
        parts[i].visible = true;
        updateDirection(i);
    }
}

int Snake::getX(){
    return parts[0].tileX;
}

int Snake::getY(){
    return parts[0].tileY;
}




