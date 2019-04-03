#include "../include/pig_dice.h"

GameState initialize_game_state(){
	GameState gst;

	gst.player = initialize_player();
	gst.ia = initialize_player("computador");
	gst.current_player = gst.player;

	return gst;
}

void render_welcome_message(){
	cout << "Bem vindo ao PIG DICE GAME" << endl;
	//colocar regras
}

bool next_action(){
	
	char action;
	cout << "\nDigite 'J' para jogar o dado ou 'P' para passar a vez\n";
	cin >> action;

	if(action == 'j' || action == 'J'){
		return roll;
	}
	else if(action == 'p' || action == 'P'){
		return hold;
	}
	else {
		cout << "Opcao invalida\n";
		return next_action();
	}
}

void process_events(GameState &gst){
	if(compare_player(gst.current_player, gst.player)){
		gst.action = next_action();
	}
	else{
		gst.action = next_action_ia();

		sleep(1); //pausa 1 segundo
		
		if(gst.action)
			cout << "\nAcao: jogar dado" << endl;
		else
			cout << "\nAcao: passar a vez" << endl;
	}

	if(gst.action==roll){
		FaceType dice = roll_dice(6);
		
		if(dice == 1){
			cout << "\nDEU PIG!" << endl;
			gst.current_player.turn_score = 0;
			gst.action = hold;
		}
		else{
			gst.current_player.turn_score += dice;

			cout << "\nDado caiu: " << dice << endl;
			cout << "Pontos do turno:" << gst.current_player.turn_score << endl;
		}
	}
}

void update(GameState &gst){
	if(gst.action==hold){
		gst.current_player.total_score += gst.current_player.turn_score;
		
		if(compare_player(gst.current_player, gst.player)){
			gst.player = gst.current_player;
			gst.current_player = gst.ia;
		}
		else{
			gst.ia = gst.current_player;
			gst.current_player = gst.player;
		}
	}
}

void render_state_game(GameState &gst){
	cout << "\nVez de: " << gst.current_player.name << endl;
	cout << gst.player.name << " tem " << gst.player.total_score << " pontos" << endl;
	cout << gst.ia.name << " tem " << gst.ia.total_score << " pontos" << endl;
}

bool gameover(GameState &gst){
	if(gst.player.total_score>=100)
		gst.winner = gst.player;
	else if(gst.ia.total_score>=100)
		gst.winner = gst.ia;
	else
		return false;

	return true;
}

void render_winner_message(GameState &gst){
	cout << "\nO ganhador foi " << gst.winner.name << " com " << gst.winner.total_score << " pontos" << endl;
}

bool compare_player(Player player1, Player player2){
	if(player1.name == player2.name)
		return true;
	else 
		return false;
}