#include "../include/pig_dice.h"

int main(){

	render_welcome_message();

	GameState gst = initialize_game_state();

	while(gameover(gst)==false){
		render_state_game(gst);
		process_events(gst);
		update(gst);
	}

	render_winner_message(gst);

	return 0;
}