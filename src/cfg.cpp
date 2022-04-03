#include "cfg.h"

// DEFAULT STATIC CFG.
int CFG::SCREEN_WIDTH = 640;
int CFG::SCREEN_HEIGHT = 480;
int CFG::FPS_LIMITED = 60;
bool CFG::VSYNC = false;
bool CFG::FULLSCREEN = false;

void CFG::loadCFG(){
    // load cfg in binary file...
    SDL_RWops* file = SDL_RWFromFile("Resources/cfg.bin", "r+b");

    if (file == NULL){
        cout << "Cannot to open the file 'cfg.bin', creating default file..." << endl;
        saveCFG();
        return;
    }

    SDL_RWread(file, &CFG::SCREEN_WIDTH, sizeof(int), 1);
    SDL_RWread(file, &CFG::SCREEN_HEIGHT, sizeof(int), 1);
    SDL_RWread(file, &CFG::FPS_LIMITED, sizeof(int), 1);
    SDL_RWread(file, &CFG::VSYNC, sizeof(bool), 1);
    SDL_RWread(file, &CFG::FULLSCREEN, sizeof(bool), 1);

    SDL_RWclose(file);
}

void CFG::saveCFG(){
    // write cfg in binary file...
    SDL_RWops* file = SDL_RWFromFile("Resources/cfg.bin", "w+b");

    SDL_RWwrite(file, &CFG::SCREEN_WIDTH, sizeof(int), 1);
    SDL_RWwrite(file, &CFG::SCREEN_HEIGHT, sizeof(int), 1);
    SDL_RWwrite(file, &CFG::FPS_LIMITED, sizeof(int), 1);
    SDL_RWwrite(file, &CFG::VSYNC, sizeof(bool), 1);
    SDL_RWwrite(file, &CFG::FULLSCREEN, sizeof(bool), 1);

    SDL_RWclose(file);

    cout << "Configuration SAVED!" << endl;
}
