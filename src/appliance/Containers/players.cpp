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

#include <iostream>
#include <stdexcept>

namespace Containers {

//:D
players::players(JPI::aux_matrix* t_players_lines)
{
	if(t_players_lines == nullptr)
		throw std::invalid_argument("players constructor nullptr t_players_lines");

	std::cout << "Starting players constructor" << std::endl;

	// m and n
	m = t_players_lines->m;
	n = t_players_lines->n;

	// m_players
	// Converting entries in "entries" to integers
	std::list<unsigned int>* l_int_entries = Utils::aux_str_to_int(t_players_lines);
	if(l_int_entries == nullptr || l_int_entries->size() != m * n)
		throw std::runtime_error("Malformed l_int_entries");

	std::cout << "Generated l_int_entries" << std::endl;

	m_players = new std::list<player*>();
	// Loop variables
	register unsigned int i = 0;
	unsigned int l_x = 0, l_y = 0;
	for(i = 0; i < m; i++) {
		l_x = l_int_entries->front();
		l_int_entries->pop_front();
		l_y = l_int_entries->front();
		l_int_entries->pop_front();

		std::cout << "Making player of positions: x = " << l_x << ", y = " << l_y << std::endl;

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
}

}
