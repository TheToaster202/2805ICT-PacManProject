#pragma once

#include "PacManGame.h"

//! Class responsible for keeping track of and displaying the score
class PacScore {
public:

	PacScore();
	
	//! Increases the score, based on the type of score
	void increaseScore(const int & scoreType, const double & currentTimer);

	//! Scores the scoring factor, based on the amount of time the game has been running for.
	double scoreScale(const double & currentTimer);

	int getScore();

private:

	int gameScore;	//Current Score
	int scaleFactor;	//Scaling Factor
	int type1, type2, type3;	//Different score amounts
	double factorConst;

};