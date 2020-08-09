#include "PacManGame.h"
#include "TextureManager.h"
#include "GameObject.h"

SDL_Renderer* PacManGame::renderer = nullptr;

GameObject* pacMan;
TileMap* map;

PacManGame::PacManGame() {

    //Game screen values
    screenWidth = 1000;
    screenHeight = 1000;

    strcpy_s(gameTitle, "Not Quite Pac Man");

    //SDL Library attributes
    gameWindow = nullptr;
    renderer = nullptr;

    isGameRunning = false;

    keyInput = 0;
}


PacManGame::~PacManGame() {
    // for some reason this causes the visual studio to throw a fit
    //delete map;
    delete pacMan;
}

//! Initialises the game by creating the window, renderer, player character and map
void PacManGame::gameInit() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

        std::cout << "Error Initialising Game Systems: " << SDL_GetError() << std::endl;

    }
    else {

        /*Remember to delete the cout statements when the game is running properly
        Or make them debug mode only*/
        std::cout << "Game systems successfully initialised" << std::endl;

        //Creates the game windows and centres it in the screen
        gameWindow = SDL_CreateWindow(gameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
        if (gameWindow) {
            std::cout << "Windows Created" << std::endl;
        }

        //Creates the game renderer
        renderer = SDL_CreateRenderer(gameWindow, -1, 0);
        if (renderer) {

            std::cout << "Renderer Created" << std::endl;
            SDL_SetRenderDrawColor(renderer, 75, 150, 255, 255);

        }

        isGameRunning = true;   //Sets the game to running

        /*Might need to move these*/
        pacMan = new GameObject("Images/PM_Sheet.png"); //Player
        map = new TileMap(); //Map

    }

}

//! Handles the events on the game window, qutting, keyboard input
void PacManGame::eventHandler() {

    SDL_Event gameEvent;
    SDL_PollEvent(&gameEvent);

    //Checks to see if any of the games events have been flagged
    switch (gameEvent.type) {
    case SDL_QUIT:
        isGameRunning = false;
        break;
    case SDL_KEYDOWN:
        
        switch (gameEvent.key.keysym.sym) {
        case SDLK_UP:
            keyInput = 1;
            break;
        case SDLK_DOWN:
            keyInput = 2;
            break;
        case SDLK_RIGHT:
            keyInput = 3;
            break;
        case SDLK_LEFT:
            keyInput = 4;
            break;
        default:
            keyInput = 0;
            break;
        }
        
        break;
    default:
        break;
    }
}

//! Handles updating ojects every frame such as player movement, score, timers and the ghosts
void PacManGame::gameUpdate() {

    pacMan->updateObject(map, keyInput);

}

//! Renders the map, player character and ghosts.
//! Works on a layering system, items rendered first are on a lower layer than those that follow
void PacManGame::gameRender() {

    SDL_RenderClear(renderer);

    map->drawMap();
    pacMan->renderObject();

    SDL_RenderPresent(renderer);

}

//! Cleans SDL2 variables by using SDL2 specific destructors
void PacManGame::cleanGame() {

    //Clears the games memory, as used by SDL
    SDL_DestroyWindow(gameWindow);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game Memory Cleaned" << std::endl;
}

bool PacManGame::gameRunning() { return isGameRunning; }