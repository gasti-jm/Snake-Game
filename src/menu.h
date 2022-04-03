#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SDL.h>

enum options{
    START_OR_RETURN_GAME,
    OPTIONS,
    EXIT
};

enum OptionsCFG{
    RESOLUTION,
    FULLSCREEN,
    VSYNC,
    FPSLIMIT
};

class Menu{
    private:
        bool visible;
        unsigned int cantOptions, optionSelected;

    public:
        Menu(bool, unsigned int);

        void handleEvents(SDL_Event&);

        bool isVisible();
};



#endif
