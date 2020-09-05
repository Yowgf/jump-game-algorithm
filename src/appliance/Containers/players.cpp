// ALG1-TP1 project appliance file
// Containers module
// Players
// ===============================
//
// Description:
// Class that implements the set of all players
//   currently active in the game. Simply a list
//   of ~players~.
/////////////////////////////////////////////////

#include "Containers/players.hpp"

#include "Utils/Utils.hpp" // aux_str_to_int

#include <stdexcept>

namespace Containers {

//:D
players::players(Utils::aux_matrix* t_players_lines)
{
	if(t_players_lines == nullptr)
		throw std::invalid_argument("players constructor nullptr t_players_lines");

	// m_cur_winners
	m_cur_winners = new std::list<player*>();
	// m_cur_winner_mov
	m_cur_winner_mov = -1;

	// m_players
	m_players = new std::list<player*>();

	// m and n
	m = t_players_lines->m;
	n = t_players_lines->n;

	if(m == 0 || n == 0)
		return;

	// m_players initialization process
	// Converting entries in "entries" to integers
	std::list<unsigned int>* l_int_entries = Utils::aux_str_to_int(t_players_lines);
	if(l_int_entries == nullptr || l_int_entries->size() != m * n)
		throw std::runtime_error("Malformed l_int_entries");

	// Loop variables
	register unsigned int i = 0;
	unsigned int l_x = 0, l_y = 0;
	for(i = 0; i < m; i++) {
		l_x = l_int_entries->front();
		l_int_entries->pop_front();
		l_y = l_int_entries->front();
		l_int_entries->pop_front();

		m_players->push_back(new player(i, l_x, l_y));
	}

	delete l_int_entries;
}

//:D
players::~players()
{
	if(m_players != nullptr)
		while(!m_players->empty()) {
			delete m_players->front();
			m_players->pop_front();
		}

	delete m_players;
	delete m_cur_winners;
}

//:D
void players::add_winner(player* t_new_winner)
{
	if(t_new_winner == nullptr)
		throw std::invalid_argument("players::set_winner nullptr t_new_winner");

	m_cur_winners->push_back(t_new_winner);
	m_cur_winner_mov = t_new_winner->get_final_mov();
}

//:D
void players::clear_winners() {
	m_cur_winners->clear();
}

//:D
unsigned int players::get_winner_mov()
{
	return m_cur_winner_mov;
}

//:D
player* players::get_abs_winner()
{
	// No winner at all!
	if(m_cur_winners->empty())
		return nullptr;

	player* winner = m_cur_winners->front();
	unsigned int min_id = winner->get_id();
	// Start iterator from second position
	std::list<player*>::iterator it = m_cur_winners->begin();
	it++;
	while(it != m_cur_winners->end()) {
		if((*it)->get_id() < min_id) {
			winner = *it;
			min_id = winner->get_id();
		}
		it++;
	}

	return winner;
}

//:D
player* players::pop_front()
{
	player* l_front_player = m_players->front();
	m_players->pop_front();
	return l_front_player;
}

//:D
bool players::empty()
{
	return m_players == nullptr ? false : m_players->empty();
}

}
