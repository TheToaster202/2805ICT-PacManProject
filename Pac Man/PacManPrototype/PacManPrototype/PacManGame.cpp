#include "PacManGame.h"
#include "TextureManager.h"
#include "GameObject.h"

/*Source code for PacMan*/

SDL_Renderer* PacManGame::renderer = nullptr;

GameObject* pacMan;

//Default ctor, itialises attributes
PacManGame::PacManGame() {

    //Game screen values
    screenWidth = 900;
    screenHeight = 800;

    strcpy_s(gameTitle, "Not Quite Pac Man");

    //SDL Library attributes
    gameWindow = nullptr;
    renderer = nullptr;

    isGameRunning = false;
}

//Default dtor
PacManGame::~PacManGame() {}

//Initialises the game
void PacManGame::gameInit() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

        std::cout << "Error Initialising Game Systems: " << SDL_GetError() << std::endl;

    }
    else {

        /*Remember to delete the cout statements when the game is running properly
        Or make them debug mode only*/
        std::cout << "Game systems successfully initialised" << std::endl;

        gameWindow = SDL_CreateWindow(gameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
        if (gameWindow) {
            std::cout << "Windows Created" << std::endl;
        }

        renderer = SDL_CreateRenderer(gameWindow, -1, 0);
        if (renderer) {

            std::cout << "Renderer Created" << std::endl;
            SDL_SetRenderDrawColor(renderer, 75, 150, 255, 255);

        }

        isGameRunning = true;

        pacMan = new GameObject("Images/PM_Sheet.png");

    }

}

void PacManGame::eventHandler() {

    SDL_Event gameEvent;
    SDL_PollEvent(&gameEvent);

    //Checks to see if any of the games events have been flagged
    switch (gameEvent.type) {
    case SDL_QUIT:
        isGameRunning = false;
        break;
    default:
        break;
    }
}

void PacManGame::gameUpdate() {

    pacMan->updateObject();

}

void PacManGame::gameRender() {

    SDL_RenderClear(renderer);

    pacMan->renderObject();

    SDL_RenderPresent(renderer);

}

void PacManGame::cleanGame() {

    //Clears the games memory, as used by SDL
    SDL_DestroyWindow(gameWindow);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game Memory Cleaned" << std::endl;
}

bool PacManGame::gameRunning() { return isGameRunning; }