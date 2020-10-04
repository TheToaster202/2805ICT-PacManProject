#pragma once
#include "PacManGame.h"
#include "Button.h"
#include "TextureManager.h"

class Settings {
public:
	Settings();
	~Settings();

	int runMenu(char const * path1, char const * path2, char const * path3);
	
private:

	int sWidth;
	int sHeight;
	int rVal;
	bool buttonPressed;

	TTF_Font* textFont;
	SDL_Color fontColour;

	SDL_Surface* sText;
	SDL_Texture* mText;
	SDL_Rect rText;

	Button one;
	Button two;
	Button three;

	SDL_Window * sWindow;
	SDL_Renderer* sRenderer;
};