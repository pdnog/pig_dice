#ifndef _PIG_DICE_H
#define _PIG_DICE_H

#include "player.h"

using value_type = int;

using acao = bool;

#define passar false

#define jogar true

/// Checks if the player has won
/*!
 * @param player The player.
 * @return true if a player has won, false otherwise.
 */

struct GameState{
	Player player1;
    Player player2;
	Player playerAtual;
    bool acao;
};
bool decidirAcao();
bool gameover(GameState &gst);

void inicializar( GameState &gst );

bool compararPlayer(Player player1, Player player2);

void processarEventos(GameState &gst);

void update(GameState &gst);

void  renderWelcome(GameState &gst);

void renderStateGame(GameState &gst);




Player initialize_player();

#endif