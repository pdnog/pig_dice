#include "../include/player.h"

Player initialize_player(){
	
	Player player;
	player.score_total = 0;
	player.current_score = 0;

	return player;
}