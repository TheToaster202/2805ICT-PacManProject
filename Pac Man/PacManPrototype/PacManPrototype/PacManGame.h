#pragma once
#ifndef PacManGame_h
#define PacManGame_h

#include <iostream>
#include <cstring>
#include <cstdlib>

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"

/// Acts as the main Parent Class for the game and is resposible for all game functionality

class PacManGame {
public:

    //! Deafult Constructor for the game
    PacManGame();
    //! Default Destructor
    ~PacManGame();

    //Game Specific methods

    //! Initialises the game
    void gameInit();
    //! Handles the events that happen on the game window
    void eventHandler();
    //! Updates item information every frame
    void gameUpdate();
    //! Handles rendering items every frame
    void gameRender();
    //! Cleans SLD2 specific variables
    void cleanGame();
    //! Returns whether or not the game is still running
    bool gameRunning();

    static SDL_Renderer* renderer;

private:
    //!Attributes
    int screenWidth, screenHeight;
    int keyInput;

    char gameTitle[19];

    bool isGameRunning;

    //! SDL variables for the window and renderer methods
    SDL_Window* gameWindow;
};

#endif /*PacManGame_h*/