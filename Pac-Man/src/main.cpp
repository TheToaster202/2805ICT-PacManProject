#include <cstdio>
#include <cstdlib>
#include <iostream>
#define SDL_MAIN_HANDLED
#include "SDL2/include/SDL2/SDL.h"

int main(int argc, char* argv[]){
    
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "Error Initialising SDL: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "SDL Successfully Initialised!" << std::endl;

    SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 100, 255, 100, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    std::cout << "Something" << std::endl;
    return EXIT_SUCCESS;
}