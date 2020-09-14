#pragma once
#include "PacManGame.h"

/// <summary>
/// Class that creates a simple Box that will house the Timer and Game Score
/// </summary>

class GameUI{
public:

	GameUI();
	
	//! Renders the UI to the screen
	void renderUI(int const& offset, int const& sW, int const & gameScore, int const & gameTimer);

	//Intialises the UI class
	void initUI(int const& offset, int const& sW);

private:

	SDL_Rect outer;
	SDL_Rect inner;

	TTF_Font* textFont;
	SDL_Color fontColour;

	SDL_Surface* sScore;
	SDL_Texture* mScore;
	SDL_Rect rScore;

	SDL_Surface* sTimer;
	SDL_Texture* mTimer;
	SDL_Rect rTimer;

	//! Renders score to the screen, part of the UI
	void renderScore(int const& offset, int const& sW, int const& gameScore, int const& gameTimer);

	//! Renders the timer to the screen, part of the UI
	void renderTimer(int const& offset, int const& sW, int const& gameScore, int const& gameTimer);
};