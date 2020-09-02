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
	std::list<node*>* m_edges;

	union tags {
		// belongs to connected graph that has [m-1, n-1] partition
		unsigned win_graph : 1;
		unsigned explored : 1;
		// largest distance from origin nodes in past BFS
		unsigned int past_min_effort; 
	} m_tags;

public:
	node(std::list<node*>* t_edges);
	~node();
};

}

#endif
