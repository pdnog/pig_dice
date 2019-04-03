#include "../include/player.h"

Player initialize_player(){
	
	Player player;

	cout << "Nome do jogador: ";
	cin >> player.name;

	player.total_score = 0;
	player.turn_score = 0;

	return player;
}

Player initialize_player(string name){
	Player player;

	player.name = name;
	player.total_score = 0;
	player.turn_score = 0;

	return player;
}