#include "PacManGame.h"
#include <cstdio>

int main(int argc, char* argv[]) {

    PacManGame* pacMan = nullptr;
    pacMan = new PacManGame();

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    pacMan->gameInit();

    //Main game loop, will run until isRunning is false
    while (pacMan->gameRunning()) {

        frameStart = SDL_GetTicks();

        pacMan->eventHandler();
        pacMan->gameRender();
        pacMan->gameUpdate();

        frameTime = SDL_GetTicks() - frameStart;

        //Caps the framerate to 60 per second, might lower it further
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    pacMan->cleanGame();

    delete pacMan;

    return EXIT_SUCCESS;
}
