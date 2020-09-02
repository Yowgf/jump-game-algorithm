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

#include "JPI/aux_matrix.hpp"

namespace Containers {

class players {
private:
	unsigned int m, n;
	std::list<player*>* m_players;

public:
	players(JPI::aux_matrix*);
	~players();
};

}

#endif
