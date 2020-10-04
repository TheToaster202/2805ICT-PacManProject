#include "SettingsMenu.h"

Settings::Settings() {
	sWidth = 600;
	sHeight = 200;
	rVal = 0;

	buttonPressed = false;

	sText = nullptr;
	mText = nullptr;

	rText.w = 400;
	rText.h = 80;

	rText.x = sWidth/2 - rText.w/2;
	rText.y = sHeight/2 - (rText.h/2) - 60;

	textFont = nullptr;
	fontColour = { 255, 255, 255 };

	sWindow = SDL_CreateWindow("Set Difficulty", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sWidth, sHeight, SDL_WINDOW_SHOWN);
	sRenderer = SDL_CreateRenderer(sWindow, -1, 0);
}

Settings::~Settings() {
	
}

int Settings::runMenu(char const* path1, char const* path2, char const* path3) {

	if (sRenderer) {
		std::cout << "New Renderer Created!" << std::endl;
		SDL_SetRenderDrawColor(sRenderer, 0, 0, 0, 255);
	}

	textFont = TTF_OpenFont("Font/ARLRDBD.ttf", 18);

	char msg[100];
	strcpy_s(msg, 100, "Set The Difficulty");

	one.initBtn(10, sHeight / 2 + (30), 21, 16, path1, sRenderer);
	two.initBtn(sWidth / 2 - (21*2), sHeight / 2 + (30), 21, 16, path2, sRenderer);
	three.initBtn(sWidth - (21*4) - 10, sHeight / 2 + 30, 21, 16, path3, sRenderer);

	sText = TTF_RenderText_Solid(textFont, msg, fontColour);
	mText = SDL_CreateTextureFromSurface(sRenderer, sText);

	SDL_RenderCopy(sRenderer, mText, NULL, &rText);

	one.renderBtn(sRenderer);
	two.renderBtn(sRenderer);
	three.renderBtn(sRenderer);

	const int FPS = 30;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	while (!buttonPressed) {

		SDL_RenderPresent(sRenderer);

		frameStart = SDL_GetTicks();

		SDL_Event sEvent;
		SDL_PollEvent(&sEvent);

		if (sEvent.type == SDL_WINDOWEVENT) {
			
			if (sEvent.window.event == SDL_WINDOWEVENT_CLOSE) {
				buttonPressed = true;
				std::cout << "QUIT" << std::endl;
			}
			
		}

		if (one.buttonPress(&sEvent)) {
			buttonPressed = true;
			rVal = 10;
		}
		else if (two.buttonPress(&sEvent)) {
			buttonPressed = true;
			rVal = 20;
		}
		else if (three.buttonPress(&sEvent)) {
			buttonPressed = true;
			rVal = 50;
		}

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	SDL_FreeSurface(sText);
	SDL_DestroyTexture(mText);

	SDL_DestroyRenderer(sRenderer);
	SDL_DestroyWindow(sWindow);

	return rVal;
}

