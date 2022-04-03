#ifndef FONTS_H_INCLUDED
#define FONTS_H_INCLUDED

#include "font_texture.h"
using std::string;

class Fonts{
    private:
        FTexture letter[255];

    public:
        Fonts();
        ~Fonts();

        bool init();
        void close();
        void drawText(string, int, int);
};

#endif
