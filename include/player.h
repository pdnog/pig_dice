#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "dice.h"
#include <string>

using namespace std;

struct Player{
	string name;
	FaceType pontosTotal;
	FaceType pontosTurno;
};

Player initialize_player();

#endif