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

namespace JPI {

class manager {
private:
	// Print the winner's name and the round
	static void print_result(Containers::player*, unsigned int);

	// Main project's algorithm
	static void exec_alg(Containers::board*, Containers::players*);

public:	
	manager(Containers::board*, Containers::players*);
};

}

#endif
