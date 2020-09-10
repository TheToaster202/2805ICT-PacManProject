#include "Score.h"
#include <cmath>

PacScore::PacScore() {
	gameScore = 0;
	scaleFactor = 0;
	type1 = 10, type2 = 100, type3 = 500;
	factorConst = -100;
}

void PacScore::increaseScore(int const & scoreType, double const & currentTimer) {

	switch (scoreType) {
	case 1:
		gameScore += type2 - (type2 * scoreScale(currentTimer));
		break;
	case 2:
		gameScore += type2 - (type2 * scoreScale(currentTimer));
		break;
	case 3:
		gameScore += type3;
		break;
	default:
		break;
	}
}

double PacScore::scoreScale(double const & currentTimer) {
	
	return exp(factorConst * currentTimer);

}