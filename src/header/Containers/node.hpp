// ALG1-TP1 project header file
// Containers module
// Node
// ============================
//
// Description:
// Class that implements a node, that is, a
//   position inside a board graph.
// The edges of every node are contained here.
/////////////////////////////////////////////////

#ifndef NODE_H
#define NODE_H 1

#include <list>

namespace Containers {
	

class node {
private:
	std::list<node*>* m_in_edges;
	std::list<node*>* m_out_edges;

	struct tags {
		// belongs to connected graph that has [m-1, n-1] partition
		bool win_graph;
		bool explored;
		// largest distance from origin nodes in past BFS
		unsigned int past_min_effort;
		// Position in board graph vector
		unsigned int pos;
		// Keeps track of the size of the last step toward this	node
		unsigned int past_movement;
	} m_tags;

public:
	node();
	~node();

	void set_in_edges(std::list<node*>*);
	void set_out_edges(std::list<node*>*);
	void set_win();
	void set_exp();
	void set_eff(unsigned int);
	void set_pos(unsigned int);
	void set_mov(unsigned int);

	std::list<node*>* get_in_edges();
	std::list<node*>* get_out_edges();
	bool is_win();
	bool is_exp();
	unsigned int get_eff();
	unsigned int get_pos();
	unsigned int get_mov();
};

}

#endif
