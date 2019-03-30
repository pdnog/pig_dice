#ifndef _DICE_H_
#define _DICE_H_

#include <random>
//#include <time>
///  Dice face type
using FaceType = unsigned short;

/// Roll the dice
/*!
 * @param number_faces Defines how many faces the dice have.
 * @return An random integer between one and the number of faces that the dice have.
 */
FaceType roll_dice(FaceType number_faces);

#endif