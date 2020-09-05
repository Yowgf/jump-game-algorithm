// ALG1-TP1 project appliance file
// Containers module
// Board
// ===============================
//
// Description:
// Class that implements the board, a graph
//   containing the possible players positions
//   (nodes). Each position's possible movements
//   is implemented in the class ~node~.
// This graph is implemented using an adjacency
//   list.
/////////////////////////////////////////////////

#include "Containers/board.hpp"

#include "Utils/Utils.hpp" // aux_str_to_int

#include <stdexcept>

namespace Containers {

//:D
void board::aux_fetch_edges(node* t_node)
{
	register unsigned int l_cur_pos = t_node->get_pos();
	register unsigned int l_cur_mov = t_node->get_mov();
	if(l_cur_pos >= m_positions->size())
		throw std::invalid_argument("aux_fetch_edges invalid l_cur_pos");

	// Useful variables
	std::list<node*>* l_cur_out_edges = t_node->get_out_edges();

	// Useful variables
	unsigned int l_pos_x = l_cur_pos % n;
	unsigned int l_pos_y = l_cur_pos / n;

	if(l_cur_mov > 0) {
		// l_new_pos is ~int~ to be able to make comparisons
		//   (unsigned int would bug really hard...)
		int l_new_pos = l_pos_x - l_cur_mov;
		unsigned int l_new_def_pos = 0;
		node* l_cur_next_node = nullptr;
		
		// Left movement
		if(l_new_pos >= 0) {
			l_new_def_pos = l_cur_pos - l_cur_mov;
			l_cur_next_node = get_node(l_new_def_pos);
			if(l_cur_mov != l_cur_next_node->get_mov()) {
				l_cur_next_node->get_in_edges()->push_back(t_node);
			}
			l_cur_out_edges->push_back(l_cur_next_node);
		}
		// Right movement
		l_new_pos = l_pos_x + l_cur_mov;
		if((unsigned int)l_new_pos < n) {
			l_new_def_pos = l_cur_pos + l_cur_mov;
			l_cur_next_node = get_node(l_new_def_pos);
			if(l_cur_mov != l_cur_next_node->get_mov()) {
				l_cur_next_node->get_in_edges()->push_back(t_node);
			}
			l_cur_out_edges->push_back(l_cur_next_node);
		}
		// Up movement
		l_new_pos = l_pos_y - l_cur_mov;
		if(l_new_pos >= 0) {
			l_new_def_pos = l_cur_pos - l_cur_mov * n;
			l_cur_next_node = get_node(l_new_def_pos);
			if(l_cur_mov != l_cur_next_node->get_mov()) {
				l_cur_next_node->get_in_edges()->push_back(t_node);
			}
			l_cur_out_edges->push_back(l_cur_next_node);
		}
		// Down movement
		l_new_pos = l_pos_y + l_cur_mov;
		if((unsigned int)l_new_pos < m) {
			l_new_def_pos = l_cur_pos + l_cur_mov * n;
			l_cur_next_node = get_node(l_new_def_pos);
			if(l_cur_mov != l_cur_next_node->get_mov()) {
				l_cur_next_node->get_in_edges()->push_back(t_node);
			}
			l_cur_out_edges->push_back(l_cur_next_node);
		}
		
	}

	return;
}

//:D
board::board(Utils::aux_matrix* t_board_lines)
{
	if(t_board_lines == nullptr)
		throw std::invalid_argument("board constructor nullptr t_board_lines");

	// m and n
	m = t_board_lines->m;
	n = t_board_lines->n;

	m_positions = new std::vector<node*>(m * n, nullptr);
	if(m == 0 || n == 0) {
			m_finish_line = nullptr;
			return;
	}

	// m_positions
	// Converting entries in "entries" to integers
	std::list<unsigned int>* l_int_entries = Utils::aux_str_to_int(t_board_lines);
	if(l_int_entries == nullptr || l_int_entries->size() != m * n)
		throw std::runtime_error("Malformed l_int_entries");

	unsigned int i = 0;
	unsigned int l_cur_mov_len = 0;
	std::vector<node*>::iterator pos_it;
	// Smoothly mounting m_positions
	// First initializing nodes, so that we can have a reference when 
	//   generating edges with aux_fetch_edges
	for(pos_it = m_positions->begin(), i = 0; pos_it != m_positions->end(); pos_it++, i++) {
		*pos_it = new node();
		(*pos_it)->set_pos(i);
		l_cur_mov_len = l_int_entries->front();
		l_int_entries->pop_front();
		(*pos_it)->set_mov(l_cur_mov_len);
	}
	// Must be done separately
	for(pos_it = m_positions->begin(); pos_it != m_positions->end(); pos_it++) {
		aux_fetch_edges(*pos_it);
	}
	
	delete l_int_entries;

	// m_finish_line
	// Has to be done after the making of the m_positions vector...
	m_finish_line = m_positions->back();
}

//:D
board::~board()
{
	register unsigned int i = 0;
	std::vector<node*>::iterator it = m_positions->begin();
	while(it != m_positions->end()) {
		delete *it;
		i++;
		it++;
	}

	m_positions->clear();
	delete m_positions;

}

//:D
unsigned int board::get_m()
{
	return m;
}

//:D
unsigned int board::get_n()
{
	return n;
}

//:D
node* board::get_node(unsigned int t_pos)
{
	try {
		return m_positions->at(t_pos);
	} catch(std::out_of_range& e) {
		return nullptr;
	}
}

//:D
node* board::get_node(unsigned int t_x, unsigned int t_y)
{
	try {
		return m_positions->at(t_x * n + t_y);
	} catch(std::out_of_range& e) {
		return nullptr;
	}
}

//:D
node* board::get_finish_line()
{
	return m_finish_line;
}

//:D
bool board::empty()
{
	return m == 0 || n == 0;
}

}

