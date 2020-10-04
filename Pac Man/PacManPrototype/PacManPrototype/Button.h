#pragma once

#include "PacManGame.h"
#include "TextureManager.h"
#include "GameTimer.h"

class Button {
public:

	Button();
	~Button();

	void initBtn(int const& xPos, int const& yPos, int const& width, int const& height, const char* texturePath, SDL_Renderer* r);
	void renderBtn(SDL_Renderer* r);
	bool buttonPress(SDL_Event * evnt);

private:

	void animateBtn();

	SDL_Rect sRect;
	SDL_Rect dRect;

	SDL_Texture* texture;

	GameTimer pressTimer;

};