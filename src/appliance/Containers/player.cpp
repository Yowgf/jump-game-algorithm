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

namespace Containers {

//:D
player::player(unsigned int t_id, unsigned int t_x, unsigned int t_y)
{
	m_id = t_id;
	m_x = t_x;
	m_y = t_y;

	m_finalist = false;
	m_final_movement = -1;
}

//:D
void player::set_finalist(bool t_is_finalist)
{
	m_finalist = t_is_finalist;
}

//:D
void player::set_final_mov(unsigned int t_final_mov)
{
	m_final_movement = t_final_mov;
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

//:D
bool player::is_finalist()
{
	return m_finalist;
}

//:D
unsigned int player::get_final_mov()
{
	return m_final_movement;
}

}
