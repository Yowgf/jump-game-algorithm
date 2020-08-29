// ALG1-TP1 project appliance file
// JPI module
// Initialization
// ===============================
//
// Description:
// Class that implements initialization routines,
//   creating objects such as current board and
//   players. It then hands these to the manager
//   class.
/////////////////////////////////////////////////

#include "JPI/init.hpp"

using namespace JPI;

init::init(int t_argc, char** t_argv)
{
	m_separated_arg* board_players = aux_separate(t_argv);

	Containers::board* board = init_board(board_players->board);
	Containers::players* players = init_players(board_players->players);
	
	manager(board, players);

	delete players;
	delete board;
	delete board_players;
}

