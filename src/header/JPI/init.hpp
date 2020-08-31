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
#include "Containers/players.hpp"

#include "JPI/manager.hpp"

#include <list>
#include <string>
#include <utility>

namespace JPI {

const int k_board_dim = 2;

// Auxiliary classes
class aux_matrix {
	public:
	int m, n;
	std::list<std::string*>* entries;

	~aux_matrix();
};

class separated_arg {
public:
	aux_matrix* board;
	aux_matrix* players;

	~separated_arg();
};

class init {
private:
	Containers::board* init_board(aux_matrix*);
	Containers::players* init_players(aux_matrix*);

	std::list<std::string*>* aux_read_entry_file(int t_argc, char** t_argv);
	separated_arg*  aux_separate(std::list<std::string*>* t_all_entries);
public:
	init(int t_argc, char** t_argv);
	~init();

};

}

#endif
