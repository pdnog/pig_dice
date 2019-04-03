#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "dice.h"
#include <string>
#include <iostream>

/// A structure to represent a player
struct Player{
	string name; //< The player's name
	FaceType total_score; //< The player's total score
	FaceType turn_score; //< The player's score in his turn
};

/// Initialize a player
/*!
 * @return A new player
 */
Player initialize_player();

/// Initialize a player
/*!
 * @param name The player's name
 * @return A new player
 */
Player initialize_player(string name);

#endif