#include "apple.h"

Apple::Apple(){
    srand(time(NULL));

    // No podemos permitir que justo al iniciar la manzana este en la misma posicion que la serpiente.
    do{
        this->tileX = 0 + rand()%(CFG::SCREEN_WIDTH / 16);
        this->tileY = 0 + rand()%(CFG::SCREEN_HEIGHT / 16);
    } while(tileX == ((CFG::SCREEN_WIDTH / 2) / 16) && tileY == ((CFG::SCREEN_HEIGHT / 2) / 16));
}


void Apple::render(){
    Drawn::drawQuad(tileX * 16, tileY * 16, applePixelSize, applePixelSize, 255, 0, 0, 255, false);
}

void Apple::setNewPosition(int snakeTileX, int snakeTileY){
    // no podemos permitir que justo caiga en la misma posicion.
    do{
        this->tileX = 0 + rand()%(CFG::SCREEN_WIDTH / 16);
        this->tileY = 0 + rand()%(CFG::SCREEN_HEIGHT / 16);
    } while(tileX == snakeTileX && tileY == snakeTileY);
}

int Apple::getX(){
    return tileX;
}

int Apple::getY(){
    return tileY;
}
