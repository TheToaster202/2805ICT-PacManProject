#include "UI.h"

GameUI::GameUI() {
	
	outer.x = 0;
	outer.y = 0;
	outer.w = 0;
	outer.h = 0;

	inner.x = 0;
	inner.y = 0;
	inner.w = 0;
	inner.h = 0;

	textFont = nullptr;
	fontColour = {255, 255, 255};

	sScore = nullptr;
	mScore = nullptr;
	rScore.x = 6;
	rScore.y = -10;
	rScore.w = 200;
	rScore.h = 100;

	sTimer = nullptr;
	mTimer = nullptr;
	rTimer.x = 306;
	rTimer.y = -10;
	rTimer.w = 200;
	rTimer.h = 100;

}

//! Sets the size of the rectangles
void GameUI::initUI(int const& offset, int const& sW) {
	outer.x = 0;
	outer.y = 0;
	outer.w = sW;
	outer.h = offset;

	inner.x = 5;
	inner.y = 5;
	inner.w = sW - 10;
	inner.h = offset - 10;

	textFont = TTF_OpenFont("Font/ARLRDBD.ttf", 24);
	
	if (textFont == nullptr) {
		std::cout << "Failed to open font: " << TTF_GetError() << std::endl;
	}
}

//! Renders the rectangles to the screen
void GameUI::renderUI(int const& offset, int const& sW, int const& gameScore, int const& gameTimer) {
	SDL_SetRenderDrawColor(PacManGame::renderer, 87, 182, 255, 255);

	SDL_RenderFillRect(PacManGame::renderer, &outer);

	SDL_SetRenderDrawColor(PacManGame::renderer, 0, 0, 0, 255);

	SDL_RenderFillRect(PacManGame::renderer, &inner);

	SDL_RenderPresent(PacManGame::renderer);

	renderScore(offset,  sW,  gameScore,  gameTimer);
	renderTimer(offset,  sW,  gameScore,  gameTimer);

}

void GameUI::renderScore(int const& offset, int const& sW, int const& gameScore, int const& gameTimer) {
	char scoreString[100];

	strcpy_s(scoreString, 100, "SCORE ");

	if (gameScore > 99999) {
		strcat_s(scoreString, 100, "99999");
	}
	else {
		char tempString[10];

		sprintf_s(tempString, 10, "%d", gameScore);

		strcat_s(scoreString, 100, tempString);
	}

	sScore = TTF_RenderText_Solid(textFont, scoreString, fontColour);
	mScore = SDL_CreateTextureFromSurface(PacManGame::renderer, sScore);

	rScore;
	rScore.x = 10;
	rScore.y = 0;
	rScore.w = 200;
	rScore.h = offset;

	SDL_RenderCopy(PacManGame::renderer, mScore, NULL, &rScore);

	SDL_FreeSurface(sScore);
	SDL_DestroyTexture(mScore);
}

void GameUI::renderTimer(int const& offset, int const& sW, int const& gameScore, int const& gameTimer) {
	char timerString[100];

	strcpy_s(timerString, 100, "TIMER: ");

	if (gameTimer > 99999) {
		strcat_s(timerString, 100, "99999");
	}
	else {
		char tempString[10];

		sprintf_s(tempString, 10, "%d", gameTimer);

		strcat_s(timerString, 100, tempString);
	}

	sTimer = TTF_RenderText_Solid(textFont, timerString, fontColour);
	mTimer = SDL_CreateTextureFromSurface(PacManGame::renderer, sTimer);

	rTimer;
	rTimer.x = sW - 210;
	rTimer.y = 0;
	rTimer.w = 200;
	rTimer.h = offset;

	SDL_RenderCopy(PacManGame::renderer, mTimer, NULL, &rTimer);

	SDL_FreeSurface(sTimer);
	SDL_DestroyTexture(mTimer);
}