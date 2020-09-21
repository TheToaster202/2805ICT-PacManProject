#include "Score.h"
#include <cmath>

PacScore::PacScore() {

	TTF_Init();
	
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

	//std::cout << gameScore << " " << scoreScale(currentTimer) << " " << currentTimer << std::endl;
	
}

double PacScore::scoreScale(double const & currentTimer) {
	
	if (currentTimer < 11) {
		return 0;
	}

	if (factorConst * log(currentTimer - 10) > 9) {
		return 9;
	}
	
	return factorConst * log(currentTimer - 10);
	
}

int PacScore::getScore() { return gameScore; }
