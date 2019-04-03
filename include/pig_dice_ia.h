#ifndef _PIG_DICE_IA_H_
#define _PIG_DICE_IA_H_

#include "player.h"

using Action = bool;

#define hold false

#define roll true

/// The next action of the IA
/*!
 *  @return true if the IA decides to roll the dice, false if the IA decides to hold
 */
Action next_action_ia();

#endif