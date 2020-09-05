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

	// Has this player gotten to the finish line?
	bool m_finalist;
	// If so, what was the size of the step he took
	//   to the node just before the last one?
	// (this will determine a winning condition)
	unsigned int m_final_movement;

public:
	player(unsigned int t_id, unsigned int t_x, unsigned int t_y);

	void set_finalist(bool);
	void set_final_mov(unsigned int);

	unsigned int get_id();
	unsigned int get_x();
	unsigned int get_y();
	bool is_finalist();
	unsigned int get_final_mov();
};

}

#endif
