// ALG1-TP1 project header file
// Containers module
// Winner
// ============================
//
// Description:
// Class that implements a winner, which is
//   simply a pair
//   (player, int) = (player_id, round).
/////////////////////////////////////////////////

#ifndef WINNER_H
#define WINNER_H 1

#include <utility>

namespace Containers {

class winner : public std::pair<player*, int>{};

}

#endif
