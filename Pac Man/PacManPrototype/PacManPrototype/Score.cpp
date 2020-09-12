#include "Score.h"
#include <cmath>

PacScore::PacScore() {
	gameScore = 0;
	scaleFactor = 0;
	type1 = 10, type2 = 100, type3 = 500;
	factorConst = 2.5;
}

void PacScore::increaseScore(int const & scoreType, double const & currentTimer) {

	switch (scoreType) {
	case 1:
		gameScore += type1 - scoreScale(currentTimer);
		break;
	case 2:
		gameScore += type2 - scoreScale(currentTimer);
		break;
	case 3:
		gameScore += type3;
		break;
	default:
		break;
	}

	std::cout << gameScore << " " << scoreScale(currentTimer) << " " << currentTimer << std::endl;
	
}

double PacScore::scoreScale(double const & currentTimer) {
	
	if (currentTimer < 11) {
		return 0;
	}
	
	return factorConst * log(currentTimer - 10);
	
}

void PacScore::renderScore() {

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

	TTF_Font* sansFont = TTF_OpenFont("Font/ARLRDBD.ttf", 24);
	SDL_Color fontColour = {255, 255, 255};
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(sansFont, scoreString, fontColour);
	SDL_Texture* message = SDL_CreateTextureFromSurface(PacManGame::renderer, surfaceMessage);

	SDL_Rect messageRect;
	messageRect.x = 10;
	messageRect.y = 10;
	messageRect.w = 100;
	messageRect.h = 100;

	SDL_RenderCopy(PacManGame::renderer, message, NULL, &messageRect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(message);

}
