#include "../include/pig_dice.h"

bool gameover(Player player){
	return player.score_total>=100;
}