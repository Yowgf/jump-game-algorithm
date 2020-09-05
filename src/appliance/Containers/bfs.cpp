// ALG1-TP1 project appliance file
// Containers module
// BFS algorithm
// ===============================
//
// Description:
// Class that implements a BFS algorithm upon a
//   graph Containers::board.
// This BFS search must look up the following
//   details:
// Loss conditions:
//   - Node disjoint of win_graph;
//   - Reach node that has been explored with greater
//     success (less distance from origin);
//   - Before win_graph set is found, reach node with
//     ~explored~ tag on.
/////////////////////////////////////////////////

#include "Containers/bfs.hpp"

#include <iostream>
#include <stdexcept>

namespace Containers {

// Auxiliary methods
void bfs::aux_push_eff(node* t_node, unsigned int t_effort, unsigned int t_mov)
{
	t_node->set_eff(t_effort);
	t_node->set_mov(t_mov);
	m_queue->push(t_node);
}

node* bfs::aux_next_node()
{
	m_queue->pop();
	return m_queue->front();
}

unsigned int bfs::aux_dist_to(node* t_destine_node)
{
	unsigned int n = m_board->get_n();
	
	unsigned int l_cur_x = m_cur_pos % n;
	unsigned int l_cur_y = m_cur_pos / n;
	unsigned int l_next_pos = t_destine_node->get_pos();
	unsigned int l_next_x =	l_next_pos % n;
	unsigned int l_next_y = l_next_pos / n;

	// X didnt change, is up/down movement
	if(l_next_x - l_cur_x == 0)
		return abs(l_next_y - l_cur_y);
	else {
		return abs(l_next_x - l_cur_x);
	}
}

// Searches
void bfs::bfs_win_found()
{
	// Lost: we already know it's not possible
	//   to get to the finish line from here.
	if(!m_cur_node->is_win())
		return;

	// If it, in constrast, is part of the win_graph,
	//   we can already set its ~finalist~ status
	m_player->set_finalist(true);

	// Pushes first node to queue
	// Current node is not explored, so had past effort 0
	aux_push_eff(m_cur_node, 0, 0);

	// Beginning queue manipulation
	// (Node by node exploration)
	while(!m_queue->empty()) {
		if(m_cur_node == nullptr)
			throw std::runtime_error("Caught nullptr node!");
		m_cur_layer = m_cur_node->get_eff();
		m_cur_pos = m_cur_node->get_pos();

		///////////////////////////////////////////////////////////////////////
		//std::cout << "Layer: " << m_cur_layer << std::endl;
		if(m_cur_layer > 500)
			throw std::runtime_error("Infinite loop");
		//std::cout << "queue size: " << m_queue->size() << std::endl;
		///////////////////////////////////////////////////////////////////////
		
		// Fetching node's edges
		m_cur_edges = m_cur_node->get_out_edges();
		// Node with no edges (0 movement length)
		if(m_cur_edges == nullptr)
			throw std::runtime_error("Caught nullptr edges!");
		//std::cout << "Node " << m_cur_node->get_pos() << " has " << m_cur_edges->size() << " edges" << std::endl;

		// Push current edges to queue
		m_it = m_cur_edges->begin();
		while(m_it != m_cur_edges->end()) {
			// If the node may have a path that leads
			//   to victory. (effort not smaller than
			//   we would have in this instance)
			//std::cout << "Checking node " << (*m_it)->get_pos() << std::endl;
			//std::cout << "Current effort " << (*m_it)->get_eff() << std::endl;
			if(m_cur_layer + 1 <= (*m_it)->get_eff()) {
				// Then add it to be the investigated
				// Set its effort to be the current layer + 1
				// Set its past movement accordingly
				m_cur_past_mov = aux_dist_to(*m_it);
				//std::cout << "Pushing node " << (*m_it)->get_pos() << std::endl;
				aux_push_eff((*m_it), m_cur_layer + 1, m_cur_past_mov);
				// We have to check if the next node is the finish line,
				//   so that we may mark movement of the player correctly.
				if((*m_it) == m_finish_line) {
					//std::cout << "Pulou do node " << m_cur_pos << " para finish line" << std::endl;
					m_player->set_final_mov(m_cur_node->get_mov());
					return;
				}
			}
			// Move on
			m_it++;
		}

		// This automatically pops the queue once
		m_cur_node = aux_next_node();
	}

	return;
}

void bfs::bfs_win_search()
{
	// Lost: already explored not-win_graph set
	if(m_cur_node->is_exp())
		return;

	// Pushes first node to queue
	// Current node is not explored, so had past effort 0
	aux_push_eff(m_cur_node, 0, 0);
	m_cur_node->set_exp();

	// Beginning queue manipulation
	// (Node by node exploration)
	while(!m_queue->empty()) {
		if(m_cur_node == nullptr)
			throw std::runtime_error("Caught nullptr node!");
		
		// Set current node as explored
		m_cur_layer = m_cur_node->get_eff();
		m_cur_pos = m_cur_node->get_pos();

		///////////////////////////////////////////////////////////////////////
		//std::cout << "Layer: " << m_cur_layer << std::endl;
		if(m_cur_layer > 500)
			throw std::runtime_error("Infinite loop");
		//std::cout << "queue size: " << m_queue->size() << std::endl;
		///////////////////////////////////////////////////////////////////////

		// Fetching node's edges
		m_cur_edges = m_cur_node->get_out_edges();
		// Node with no edges (0 movement length)
		if(m_cur_edges == nullptr)
			throw std::runtime_error("Caught nullptr edges!");

		// Push current edges to queue
		m_it = m_cur_edges->begin();
		while(m_it != m_cur_edges->end()) {
			// If the node nas not been explored before
			if(!(*m_it)->is_exp()) {
				// Then add it to be the explored later
				// Set its effort to be the current layer + 1
				// Set its past movement accordingly
				(*m_it)->set_exp();
				m_cur_past_mov = aux_dist_to(*m_it);
				//std::cout << "Pushing node " << m_board->get_pos(*m_it) << std::endl;
				aux_push_eff((*m_it), m_cur_layer + 1, m_cur_past_mov);
				// We have to check if the next node is the finish line,
				//   so that we may mark movement of the player correctly.
				if((*m_it) == m_finish_line) {
					//std::cout << "Pulou do node " << m_cur_pos << " para finish line" << std::endl;
					m_player->set_final_mov(m_cur_node->get_mov());
				}
			}
			// Move on
			m_it++;
		}
		// This automatically pops the queue
		m_cur_node = aux_next_node();

	}
	
	// Finally, checking if we found a win graph
	if(m_finish_line->is_exp()) {
		//std::cout << "We found node " << m_board->get_pos(m_finish_line) << '!' << std::endl;
		// If so, we can make a backwards search, to
		//   find all the nodes that have a path into
		//   the win graph.

		//std::cout << "Building win_graph" << std::endl;
		m_cur_node = m_finish_line;
		m_cur_node->set_win();
		m_queue->push(m_cur_node);
		while(!m_queue->empty()) {
			if(m_cur_node == nullptr)
				throw std::runtime_error("Caught nullptr node!");

			m_cur_edges = m_cur_node->get_in_edges();
			if(m_cur_edges == nullptr)
				throw std::runtime_error("Caught nullptr edges!");
			m_it = m_cur_edges->begin();
			while(m_it != m_cur_edges->end()) {
				if(!(*m_it)->is_win()) {
					// Set is as part of the win_graph
					(*m_it)->set_win();
					m_queue->push(*m_it);
					//std::cout << (*m_it)->get_pos() << ' ';
				}
				// Move on
				m_it++;
			}
			m_cur_node = aux_next_node();
		}
		//std::cout << std::endl;

		// Setting our player to be a finalist
		m_player->set_finalist(true);
		// Setting this to be the final movement of our player
		// Setting our identification variable to be true.
		//std::cout << "Win_graph is settled !!!" << std::endl;
	}

	return;
}

// High level algorithm manager
bfs::bfs(player* t_player, board* t_board)
{
	m_cur_node = t_board->get_node(t_player->get_x(), t_player->get_y());
	if(m_cur_node == nullptr)
		throw std::invalid_argument("bfs::bfs t_player node not found");

	// Pointers
	m_queue = new std::queue<node*>();
	// This queue will be initialized inside subsequent calls
	m_cur_edges = nullptr;

	m_finish_line = t_board->get_finish_line();
	m_player = t_player;
	m_board = t_board;

	// Useful values
	m_cur_layer = 0;
	m_cur_past_mov = 0;
	m_cur_pos = m_cur_node->get_pos();
	m_found_win = m_finish_line->is_win();

	// The methods for finding the win_graph set and
	//   searching after it's been found are very
	//   different, so we want to divide them into two.
	if(m_found_win)
		bfs_win_found();
	else
		bfs_win_search();
}

bfs::~bfs()
{
	//std::cout << "Trying to delete bfs structures..." << std::endl;

	if(m_queue != nullptr)
		while(!m_queue->empty())
			m_queue->pop();
	delete m_queue;
	// Extern (should delete!)
	m_cur_node = nullptr;
	m_cur_edges = nullptr;
	//std::cout << "Deleted bfs structures." << std::endl;
}

}
