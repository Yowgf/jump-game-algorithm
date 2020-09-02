// ALG1-TP1 project appliance file
// Containers module
// Node
// ============================
//
// Description:
// Class that implements a node, that is, a
//   position inside a board graph.
// The edges of every node are contained here.
/////////////////////////////////////////////////

#include "Containers/board.hpp"
#include "Containers/node.hpp"

namespace Containers {

//:D
node::node(std::list<node*>* t_edges)
{
	// m_edges
	m_edges = t_edges;
	
	// tags
	m_tags.win_graph = 0;
	m_tags.explored = 0;
	m_tags.past_min_effort = 0;
}

//:D
node::~node()
{
	// The responsibility to delete the nodes pointed
	//   to by theedges is of the class ~board~.
	delete m_edges;
}

}


