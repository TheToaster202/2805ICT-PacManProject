#pragma once
#ifndef PacManGame_h
#define PacManGame_h

#include <iostream>
#include <cstring>
#include <cstdlib>

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"

/*Header File for PacMan, need to practise class method seperation anyway...*/

class PacManGame {
public:

    //Deafult Constructor/Destructor for the game
    PacManGame();
    ~PacManGame();

    //Game Specific methods

    void gameInit();
    void eventHandler();
    void gameUpdate();
    void gameRender();
    void cleanGame();

    bool gameRunning();

    static SDL_Renderer* renderer;

private:
    int screenWidth, screenHeight;

    char gameTitle[19];

    bool isGameRunning;

    //SDL variables for the window and renderer methods
        /*can always tell the library is old when it requires the use of pointers rather than references*/
    SDL_Window* gameWindow;

};

#endif /*PacManGame_h*/