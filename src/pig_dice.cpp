#include <iostream>

#include "../include/pig_dice.h"
#include "../include/player.h"
#include "../include/dice.h"



bool gameover(GameState &gst ){
	return gst.player1.pontosTotal>=100 || gst.player2.pontosTotal>=100 ;
}

void inicializar( GameState &gst ){
	 gst.player1.pontosTotal = 0;
	 gst.player2.pontosTotal = 0;
	 gst.player1.pontosTurno = 0;
	 gst.player2.pontosTurno = 0;
	 gst.playerAtual = gst.player1;
}

bool compararPlayer(Player player1, Player player2){
	if(player1.name == player2.name){
		return true;
	}else 
	return false;
}

void processarEventos(GameState &gst){
	acao acaoTurno = decidirAcao();
	if(compararPlayer(gst.player1, gst.playerAtual)){
		gst.playerAtual = gst.player1;
		
	}
	if(acaoTurno == jogar){
		FaceType dado = roll_dice(6);
		if(dado == 1){
			cout << "DEU PIG!!";
			gst.playerAtual.pontosTurno = 0;
			gst.acao = passar;
		}
		else{
			cout << "Dado caiu: " << dado << endl;
			cout << "Pontos do turno:" << gst.playerAtual.pontosTurno + dado << endl;
			gst.playerAtual.pontosTurno += dado;
		}
	}else{
		gst.acao = passar;
	}
}

void update(GameState &gst){
	if(gst.acao == passar){
		gst.playerAtual.pontosTotal += gst.playerAtual.pontosTurno;
		if(compararPlayer(gst.playerAtual, gst.player1)){
			gst.player1 = gst.playerAtual;
			gst.playerAtual = gst.player2;

		}else{
			gst.player2 = gst.playerAtual;
			gst.playerAtual = gst.player1;
			
		}
	}
}

void  renderWelcome(GameState &gst){
	cout << "Bem vindo ao PIG DICE GAME" << endl;
}

void renderStateGame(GameState &gst){
	cout << "\nVez de: " << gst.playerAtual.name << endl;
	cout << gst.player1.name << " tem " << gst.player1.pontosTotal << " pontos" << endl;
	cout << gst.player2.name << " tem " << gst.player2.pontosTotal << " pontos" << endl;
}

bool decidirAcao(){
	acao acaoTurno;
	string a;
	cout << "Digite J para jogar e P para passar \n";
	cin >> a;
	if(a == "j"){
		acaoTurno = jogar;
	}else{
		acaoTurno = passar;
	}
	return acaoTurno; 
}
