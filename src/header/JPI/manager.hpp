// ALG1-TP1 project header file
// JPI module
// Manager
// ============================
//
// Description:
// Class that receives the board and players from
//   ~init~ class, and then executes the game
//   algorithm at a high level, delegating tasks
//   to ~Containers~ module.
/////////////////////////////////////////////////

#ifndef MANAGER_H
#define MANAGER_H 1

#include "Containers/board.hpp"
#include "Containers/players.hpp"
#include "Containers/player.hpp"


namespace JPI {

struct winner {
	Containers::player* pl;
	int round;
};

class manager {
private:
	static void print_result(winner*);
	static winner* exec_alg(Containers::board*, Containers::players*);

public:	
	manager(Containers::board*, Containers::players*);
};

}

#endif
