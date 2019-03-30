#include "../include/dice.h"

FaceType roll_dice(FaceType number_faces){
	srand(time(NULL));
	return rand() % number_faces + 1;
}