// ALG1-TP1 project header file
// Containers module
// Players
// ============================
//
// Description:
// Class that implements the set of all players
//   currently active in the game. Simply a list
//   of ~players~.
/////////////////////////////////////////////////

#ifndef PLAYERS_H
#define PLAYERS_H 1

#include "Containers/player.hpp"
#include "Utils/aux_matrix.hpp"

namespace Containers {

class players {
private:
	unsigned int m, n;
	std::list<player*>* m_players;

	// Current best players
	//   Can be beat by someone who reaches
	//   the finish line with less effort.
	// The real winners will be decided in the
	//   manager class, after the algorithm is
	//   executed for all the players.
	std::list<player*>* m_cur_winners;
	// The past movement of the winners
	//  (Necessarily the winners have the same
	//  past movement).
	unsigned int m_cur_winner_mov;

public:
	players(Utils::aux_matrix*);
	~players();

	void add_winner(player*);
	void clear_winners();
	unsigned int get_winner_mov();
	// Finds player with least player_id (last winning condition)
	//   Concretely, winner is the player with least player_id, 
	//   among those who were left inside the ~m_cur_winners~ list
	Containers::player* get_abs_winner();

	player* pop_front();
	bool empty();
};

}

#endif
