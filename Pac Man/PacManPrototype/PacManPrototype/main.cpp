#include "PacManGame.h"
#include <cstdio>

//Test File to get SDL2 to link and run properly, probably won't be used for too long
int main(int argc, char* argv[]) {

    PacManGame* pacMan = nullptr;
    pacMan = new PacManGame();

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    pacMan->gameInit();

    while (pacMan->gameRunning()) {

        frameStart = SDL_GetTicks();

        pacMan->eventHandler();
        pacMan->gameRender();
        pacMan->gameUpdate();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    pacMan->cleanGame();

    delete pacMan;

    return EXIT_SUCCESS;
}
