#include "engine.h"

Engine::Engine() {
	isRunning = true;
}

bool Engine::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL could not initialize! ERROR CODE: " << SDL_GetError() << std::endl;
		return false;
	}

	CFG::loadCFG();

	if (window.init() == false) {
		std::cout << "SDL could not be created! ERROR CODE: " << SDL_GetError() << std::endl;
		return false;
	}

	Render::renderer = window.createRender();
	if (Render::renderer == NULL) {
		std::cout << "Renderer could not be created! ERROR CODE: " << SDL_GetError() << std::endl;
		return false;
	}

	if(font.init() == false){
        std::cout << "Font system could not initialize! ERROR CODE: " << SDL_GetError() << std::endl;
        return false;
	}

	// init ok!
	return true;
}

void Engine::close() {
	SDL_DestroyRenderer(Render::renderer); // destroy render.
	window.close(); // destroy window.
	font.close(); // destroy font system

	// Quit SDL Systems.
    TTF_Quit();
	SDL_Quit();
}

void Engine::mainLoop() {
    fpsTimer.start(); // init timer.

	while (isRunning) {
        renderScreen();
        checkEvents();
        UpdateFPS();
	}
}


void Engine::UpdateFPS(){
    if (SDL_GetTicks() >= fpsTimer.getTicks() - 1000){
        fpsTimer.start();
        FPS = countedFrames;
        countedFrames = 0;
    }

    countedFrames++;
}


void Engine::renderScreen() {
    if(window.isMinimized()) return;

    std::stringstream score, textFPS;
    score << "Score: " << gameplay.getScore();
    textFPS << FPS << " FPS";

	// clear screen
	SDL_SetRenderDrawColor(Render::renderer, 0, 0, 0, 0);
	SDL_RenderClear(Render::renderer);

    //if (gameplay.getMenu() == renderMenu::PRINCIPAL){
    //    renderPrincipalMenu();
    //} else {
        if(gameplay.isPaused()) {
            renderPause();
        } else {
            gameplay.render();
            font.drawText(score.str(), 0, 20);
            font.drawText(textFPS.str(), 0, 0);
        }
    //}


	// update screen
	SDL_RenderPresent(Render::renderer);
}

void Engine::renderPrincipalMenu(){
    font.drawText("SNAKE GAME",
                (CFG::SCREEN_WIDTH / 2) - 80,
                (CFG::SCREEN_HEIGHT / 2) - 100);

    font.drawText("START GAME",
                  (CFG::SCREEN_WIDTH / 2) - 80,
                  (CFG::SCREEN_HEIGHT / 2));

    font.drawText("OPTIONS",
                  (CFG::SCREEN_WIDTH / 2) - 56,
                  (CFG::SCREEN_HEIGHT / 2) + 21);

    font.drawText("EXIT GAME",
                  (CFG::SCREEN_WIDTH / 2) - 72,
                  (CFG::SCREEN_HEIGHT / 2) + 42);

    font.drawText(">", (CFG::SCREEN_WIDTH / 2) - 100,
                  (CFG::SCREEN_HEIGHT / 2));
}

void Engine::renderPause(){
    font.drawText("PAUSE",
                (CFG::SCREEN_WIDTH / 2) - 42,
                (CFG::SCREEN_HEIGHT / 2) - 100);

    font.drawText("RETURN GAME",
                  (CFG::SCREEN_WIDTH / 2) - 88,
                  (CFG::SCREEN_HEIGHT / 2));

    font.drawText("OPTIONS",
                  (CFG::SCREEN_WIDTH / 2) - 56,
                  (CFG::SCREEN_HEIGHT / 2) + 21);

    font.drawText("EXIT GAME",
                  (CFG::SCREEN_WIDTH / 2) - 72,
                  (CFG::SCREEN_HEIGHT / 2) + 42);
}

void Engine::checkEvents() {
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT){
            isRunning = false;
		} else if(e.type == SDL_KEYDOWN && e.key.repeat == 0){
		    if(e.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
            gameplay.handleEvents(e);
		}
		window.handleWindowEvents(e);
	}
}
