
#include <iostream>

#include "../include/pig_dice.h"
#include "../include/dice.h"
#include "../include/player.h"



int main(){
	cout << "Bem vindo ao PIG DICE GAME" << endl;
	string name1, name2;
	cout << "Digite o nome do jogador 1:";
	cin >> name1;
	cout << "Digite o nome do jogador 2:";
	cin >> name2;


	GameState gst;

	gst.player1.name = name1; 
	gst.player2.name = name2; 
	
	inicializar(gst);
	//renderWelcome(gst);
	//fazer função pra pegar o nome
	while(!(gameover(gst))){
		processarEventos(gst);
		update(gst);
		renderStateGame(gst);
	}

	return 0;
}