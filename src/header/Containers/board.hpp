// ALG1-TP1 project header file
// Containers module
// Board
// ============================
//
// Description:
// Class that implements the board, a matrix
//   containing the possible players positions,
//   and each position's movement length.
/////////////////////////////////////////////////

#ifndef BOARD_H
#define BOARD_H 1

#include "JPI/aux_matrix.hpp"

namespace Containers {

class board {

public:
	board(JPI::aux_matrix* t_board_lines);
};

}

#endif
