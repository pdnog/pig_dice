#include "../include/dice.h"

FaceType roll_dice(FaceType number_faces){
	default_random_engine generator;
	generator.seed(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<FaceType> distribution(1,number_faces);
	return distribution(generator);
}