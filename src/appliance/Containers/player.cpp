// ALG1-TP1 project appliance file
// Containers module
// Player
// ===============================
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

#include "Containers/player.hpp"

#include "Containers/board.hpp"

namespace Containers {

//:D
player::player(unsigned int t_id, unsigned int t_x, unsigned int t_y)
{
	m_id = t_id;
	m_x = t_x;
	m_y = t_y;
}

//:D
unsigned int player::get_id()
{
	return m_id;
}

//:D
unsigned int player::get_x()
{
	return m_x;
}

//:D
unsigned int player::get_y()
{
	return m_y;
}

}
