#ifndef APPLE_H_INCLUDED
#define APPLE_H_INCLUDED

#include <stdlib.h>
#include <time.h>

#include "drawn.h"
#include "cfg.h"

class Apple{
    private:
        const int applePixelSize = 13; // Tamaño de la manzana x pixeles.
        int tileX, tileY; // Posicion de la manzana

    public:
        Apple();

        void render();
        void setNewPosition(int, int);

        int getX();
        int getY();
};


#endif
