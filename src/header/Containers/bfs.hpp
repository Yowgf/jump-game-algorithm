// ALG1-TP1 project header file
// Containers module
// BFS algorithm
// ============================
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

#ifndef BFS_H
#define BFS_H 1

#include "Containers/board.hpp"
#include "Containers/player.hpp"

#include <list>
#include <queue>

namespace Containers {

class bfs {
private:
	// Pointers
	// Extern
	node* m_cur_node;
	// Local
	std::queue<node*>* m_queue;
	// Extern
	std::list<node*>* m_cur_edges;
	// For easy access
	node* m_finish_line;
	player* m_player;
	board* m_board;

	// Local iterator object
	std::list<node*>::iterator m_it;

	// Useful values
	unsigned int m_cur_layer;
	unsigned int m_cur_past_mov;
	unsigned int m_cur_pos;
	bool m_found_win;

	// Two parts
	// If win_graph has been found, then:
	void bfs_win_found();
	// If not... SEARCH FOR IT!
	void bfs_win_search();

	// Methods that help with bfs execution
	// Queue manipulation
	void aux_push_eff(node* t_node, unsigned int t_effort, unsigned int t_mov);
	node* aux_next_node();
	unsigned int aux_dist_to(node* t_destine_node);

public:
	// Breadth-first algorithm upon graph ~t_board~,
	//   with origin at ~t_player~'s node.
	bfs(player*, board*);
	~bfs();
};

}

#endif
