#ifndef _PIG_DICE_H_
#define _PIG_DICE_H_

#include "player.h"

using Action = bool;

#define hold false

#define roll true

/// A structure to represent the game state
struct GameState{
	Player player1; //< The first player
    Player player2; //< The second player
	Player current_player; //< The turn's player
	Player winner; //< The winner
    Action action; //< The action of the turn's player
};

/// Initialize the game state
/*!
 * @return void.
 */
GameState initialize_game_state();

/// Prints a welcome message on the standard output
/*!
 * @return void.
 */
void render_welcome_message();

/// Asks player for the next action, which might be either roll or hold
/*!
 * @return true if the player decides to roll the dice, false if the player decides to hold
 */
bool next_action();

/// Process the game events
/*!
 * @brief Asks the current player for the next action (either roll the dice or hold)
 * @param gst The game state
 * @return void.
 */
void process_events(GameState &gst);

/// Update the game state
/*!
 * @brief The method process the action chosen by the current player. This might add points to the current's player turn or pass the turn to the opponent
 * @param gst The game state
 * @return void
 */
void update(GameState &gst);

/// Print the game overal state on the standard output
/*!
 * @param gst The game state
 * @return void
 */
void render_state_game(GameState &gst);

/// Checks in the game state if one player has won
/*!
 * @param gst The game state
 * @return true if a player has won, false otherwise
 */
bool gameover(GameState &gst);

/// Prints a message for the winner
/*!
 * @return void
 */
void render_winner_message(GameState &gst);

/// Checks if the player1's name is the same as player2's name
/*!
 * @param player1 The first player
 * @param player2 The second player
 * @return true if the player1's name is the same as the player2's name, false otherwise
 */
bool compare_player(Player player1, Player player2);

#endif