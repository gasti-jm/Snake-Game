#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "cfg.h"
#include "drawn.h"
#include "timer.h"

#define MAX_LENGTH_SNAKE 40

// Direccion en la que va la serpiente.
enum Direction{
    NORTH,
    SOUTH,
    EAST,
    WEST
};

struct snakeParts{
    int tileX, tileY;
    int direction;
    int tileChangeDirecX, tileChangeDirecY;
    bool visible;
};

class Snake{
    private:
        const int snakePixelSize = 13;
        const int NONE = -100;
        snakeParts parts[MAX_LENGTH_SNAKE];
        Timer updateSnake;

    public:
        Snake();

        void render();
        void setNewDirection(int);
        void updatePos(int);

        void addNewBody();
        void updateDirection(int);
        void accommodateSnake(int);
        bool checkDirection(int);
        bool checkCollision();
        void resetGame();

        int getX();
        int getY();
};

#endif
