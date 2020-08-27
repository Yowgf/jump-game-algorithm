// ALG1-TP1 project header file
// JPI module
// Initialization
// ============================
//
// Description:
// Class that implements initialization routines,
//   creating objects such as current board and
//   players. It then hands these to the manager
//   class.
/////////////////////////////////////////////////

#ifndef INIT_H
#define INIT_H 1

#include "Containers/board.hpp"
#include "Containers/player.hpp"

#include "JPI/manager.hpp"

#include <list>

namespace JPI {

class init {
private:
	Containers::board* init_board();
	std::list<Containers::player*>* init_players();

	void play();
public:
	init();
	~init();

};

}

#endif
