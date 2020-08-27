// ALG1-TP1 project header file
// JPI module
// Manager
// ============================
//
// Description:
// Class that delegates tasks for Containers to
//   handle.
/////////////////////////////////////////////////

#ifndef MANAGER_H
#define MANAGER_H 1

#include "Containers/board.hpp"
#include "Containers/player.hpp"

#include <list>

namespace JPI {

struct winner {
	Containers::player* pl;
	int round;
};

class manager {
private:
	winner* exec_alg(Containers::board*, std::list<Containers::player*>*);
	void print_result(winner*);

public:
	manager(Containers::board*, std::list<Containers::player*>*);
};

}

#endif
