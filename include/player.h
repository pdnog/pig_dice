#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "dice.h"
#include <string>

struct Player{
	std::string name;
	FaceType score_total;
	FaceType current_score;
};

Player initialize_player();

#endif