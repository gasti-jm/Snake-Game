#ifndef CFG_H_INCLUDED
#define CFG_H_INCLUDED

#include <SDL.h>
#include <iostream>
using std::cout;
using std::endl;

class CFG{
    public:
        static int SCREEN_WIDTH, SCREEN_HEIGHT, FPS_LIMITED;
        static bool VSYNC, FULLSCREEN;

        static void loadCFG();
        static void saveCFG();
};

#endif
