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
#include "Containers/winner.hpp"

namespace JPI {

class manager {
private:
	static void print_result(Containers::winner*);
	static void exec_alg(Containers::board*, Containers::players*);

public:	
	manager(Containers::board*, Containers::players*);
};

}

#endif
