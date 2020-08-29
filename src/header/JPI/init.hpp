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

#include <vector>
#include <utility>

namespace JPI {

class init {
private:
	struct m_aux_matrix{
		int m, n;
		char** entries;
	};

	struct m_separated_arg {
		m_aux_matrix* board;
		m_aux_matrix* players;
	};

	Containers::board* init_board(m_aux_matrix*);
	Containers::players* init_players(m_aux_matrix*);

	void play();

	m_separated_arg*  aux_separate(char** t_argv);
public:
	init(int t_argc, char** t_argv);
	~init();

};

}

#endif
