#include "PacManGame.h"
#include "TextureManager.h"
#include "GameObject.h"


/*Source code for PacMan*/

SDL_Renderer* PacManGame::renderer = nullptr;

GameObject* pacMan;
TileMap* map;

//Default ctor, itialises attributes
PacManGame::PacManGame() {

    //Game screen values
    screenWidth = 1000;
    screenHeight = 1000;

    strcpy_s(gameTitle, "Not Quite Pac Man");

    //SDL Library attributes
    gameWindow = nullptr;
    renderer = nullptr;

    isGameRunning = false;
}

//Default dtor
PacManGame::~PacManGame() {
    // for some reason this causes the visual studio to throw a fit
    //delete map;
    delete pacMan;
}

//Initialises the game
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

//Handles the events on the game window
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

//Items to be updated every frame
void PacManGame::gameUpdate() {

    pacMan->updateObject(map);

}

//Items to be rendered every frame
void PacManGame::gameRender() {

    SDL_RenderClear(renderer);

    map->drawMap();
    pacMan->renderObject();

    SDL_RenderPresent(renderer);

}

//Cleans SDL2 variables
void PacManGame::cleanGame() {

    //Clears the games memory, as used by SDL
    SDL_DestroyWindow(gameWindow);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game Memory Cleaned" << std::endl;
}

//Returns if the game is running
bool PacManGame::gameRunning() { return isGameRunning; }