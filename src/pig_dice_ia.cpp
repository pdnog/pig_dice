#include "../include/pig_dice_ia.h"

Action next_action_ia(){
	if(roll_dice(5)%2==0)
		return hold;
	else
		return roll;
}