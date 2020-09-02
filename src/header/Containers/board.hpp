// ALG1-TP1 project header file
// Containers module
// Board
// ============================
//
// Description:
// Class that implements the board, a graph
//   containing the possible players positions
//   (nodes). Each position's possible movements
//   is implemented in the class ~node~.
// This graph is implemented using an adjacency
//   list.
/////////////////////////////////////////////////

#ifndef BOARD_H
#define BOARD_H 1

#include "Containers/node.hpp"
#include "Containers/player.hpp"
#include "JPI/aux_matrix.hpp"

#include <vector>

namespace Containers {

class board {
private:
	unsigned int m, n;
	std::vector<node*>* m_positions;
	// node in position [m - 1, n - 1]
	node* m_finish_line;

	// Returns edges to node in position t_pos
	std::list<node*>* aux_fetch_edges 
		(unsigned int t_pos, unsigned t_mov_len);

public:
	board(JPI::aux_matrix* t_board_lines);
	~board();

	node* get_node(unsigned int t_pos);
	node* get_node(unsigned int t_x, unsigned int t_y);
	node* get_finish_line();
};

}

#endif
