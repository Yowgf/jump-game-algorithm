// ALG1-TP1 project header file
// Containers module
// Player
// ============================
//
// Description:
// Class that implements the player, an entity
//   that interacts with the board through valid
//   movements, and keeps track of its own
//   position.
// In fact, the only things this class is
//   responsible for is holding a player id and
//   its initial position.
/////////////////////////////////////////////////

#ifndef PLAYER_H
#define PLAYER_H 1

namespace Containers {

class player {
private:
	unsigned int m_id;
	unsigned int m_x;
	unsigned int m_y;

public:
	player(unsigned int t_id, unsigned int t_x, unsigned int t_y);

	unsigned int get_id();
	unsigned int get_x();
	unsigned int get_y();
};

}

#endif
