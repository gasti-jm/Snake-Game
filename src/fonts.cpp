#include "fonts.h"

Fonts::Fonts(){

}

Fonts::~Fonts(){

}

bool Fonts::init(){
    if(TTF_Init() == -1) return false;
    if(Render::initTTF() == false) return false;

    SDL_Color textColor = { 255, 255, 255 };

    //ASCII CODE
    for(int i = 1; i <= 255; i++){
        letter[i-1].loadFromRenderedText(static_cast<char>(i), textColor);
    }

    return true;
}

void Fonts::close(){
    for (int i = 0; i < 255; i++) letter[i].free();
    TTF_CloseFont(Render::fileFont);
    Render::fileFont = NULL;
}

void Fonts::drawText(string text, int x, int y){
    int ascii = 0, space = 0;
    if (text == "") return;
    const char* cText = text.c_str(); // give len and ascii

    for (int a = 0; a < static_cast<int>(text.length()); a++){
        ascii = (int)cText[a] - 1; // give ascii
        if (ascii > 255) ascii = 0;

        letter[ascii].render((x + space), y);
        if (ascii != 31){
            space += letter[ascii].getWidth() + 2;
        } else {
            space += 4;
        }

    }
}

