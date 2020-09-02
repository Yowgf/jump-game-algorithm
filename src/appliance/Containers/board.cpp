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

#include <iostream>
#include <stdexcept>

namespace Containers {

//:D
std::list<node*>* board::aux_fetch_edges(unsigned int t_pos, unsigned int t_mov_len)
{
	if(t_pos >= m_positions->size())
		throw std::invalid_argument("aux_fetch_edges invalid t_pos");
	// Return variable
	std::list<node*>* edges = new std::list<node*>();

	// Useful variables
	unsigned int l_pos_x = t_pos % n;
	unsigned int l_pos_y = t_pos / n;

	std::cout << "Node " << t_pos << " with x and y: " << l_pos_x << ' ' << l_pos_y << std::endl;
	// Left movement
	int l_new_pos = l_pos_x - t_mov_len;
	if(l_new_pos > 0)
		edges->push_back(get_node(t_pos - t_mov_len));
	// Right movement
	l_new_pos = l_pos_x + t_mov_len;
	if((unsigned int)l_new_pos < n)
		edges->push_back(get_node(t_pos + t_mov_len));
	// Up movement
	l_new_pos = l_pos_y - t_mov_len;
	if(l_new_pos > 0)
		edges->push_back(get_node(t_pos - t_mov_len * n));
	// Down movement
	l_new_pos = l_pos_y + t_mov_len;
	if((unsigned int)l_new_pos < m)
		edges->push_back(get_node(t_pos + t_mov_len * n));

	std::cout << "Finished fetching edges." << std::endl;
	
	if(edges->empty()){
		delete edges;
		return nullptr;
	}
	
	return edges;
}

//:D
board::board(JPI::aux_matrix* t_board_lines)
{
	if(t_board_lines == nullptr)
		throw std::invalid_argument("board constructor nullptr t_board_lines");

	std::cout << "Starting board constructor" << std::endl;

	// m and n
	m = t_board_lines->m;
	n = t_board_lines->n;

	// m_positions
	// Converting entries in "entries" to integers
	std::list<unsigned int>* l_int_entries = Utils::aux_str_to_int(t_board_lines);
	if(l_int_entries == nullptr || l_int_entries->size() != m * n)
		throw std::runtime_error("Malformed l_int_entries");

	std::cout << "Generated l_int_entries" << std::endl;

	// Smoothly mounting m_positions
	m_positions = new std::vector<node*>(m * n, nullptr);
	unsigned int i = 0;
	unsigned int l_cur_mov_len = 0;
	std::list<node*>* l_cur_edges = nullptr;
	std::vector<node*>::iterator pos_it = m_positions->begin();
	for(; pos_it != m_positions->end(); pos_it++, i++) {
		l_cur_mov_len = l_int_entries->front();
		l_cur_edges = aux_fetch_edges(i, l_cur_mov_len);
		*pos_it = new node(l_cur_edges);
		l_int_entries->pop_front();
	}

	// m_finish_line
	m_finish_line = m_positions->back();
	
	delete l_int_entries;
}

//:D
board::~board()
{
	std::vector<node*>::iterator it = m_positions->begin();
	while(it != m_positions->end()) {
		delete *it;
		it++;
	}
	delete m_positions;
}

//:D
node* board::get_node(unsigned int t_pos)
{
	if(t_pos >= m_positions->size())
		throw std::out_of_range(std::string("Trying to get invalid node ") += std::to_string(t_pos));

	return m_positions->at(t_pos);
}

//:D
node* board::get_node(unsigned int t_x, unsigned int t_y)
{
	if(t_x >= m || t_y >= n)
		throw std::invalid_argument(std::string("Trying to get invalid node: x = ")
			+= std::to_string(t_x) += std::string(", y = ") += std::to_string(t_y));

	return m_positions->at(t_x * n + t_y);
}

//:D
node* board::get_finish_line()
{
	return m_finish_line;
}


}

