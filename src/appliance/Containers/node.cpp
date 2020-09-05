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

#include <iostream>

namespace Containers {

//:D
node::node()
{
	m_in_edges = new std::list<node*>();
	m_out_edges = new std::list<node*>();

	// tags
	m_tags.win_graph = false;
	m_tags.explored = false;
	m_tags.past_min_effort = -1;
}

//:D
node::~node()
{
	// The responsibility to delete the nodes pointed
	//   to by the edges is of the class ~board~.
	if(m_in_edges != nullptr)
		m_in_edges->clear();
	delete m_in_edges;
	if(m_out_edges != nullptr)
		m_out_edges->clear();
	delete m_out_edges;
}

//:D
void node::set_in_edges(std::list<node*>* t_in_edges)
{
	if(m_in_edges != nullptr)
		m_in_edges->clear();
	delete m_in_edges;
	m_in_edges = t_in_edges;
}

//:D
void node::set_out_edges(std::list<node*>* t_out_edges)
{
	if(m_out_edges != nullptr)
		m_out_edges->clear();
	delete m_out_edges;
	m_out_edges = t_out_edges;
}

//:D
void node::set_win()
{
	m_tags.win_graph = true;
}

//:D
void node::set_exp()
{
	m_tags.explored = true;
}

//:D
void node::set_eff(unsigned int t_eff)
{
	m_tags.past_min_effort = t_eff;
}

//:D
void node::set_pos(unsigned int t_pos)
{
	m_tags.pos = t_pos;
}

//:D
void node::set_mov(unsigned int t_mov)
{
	m_tags.past_movement = t_mov;
}

//:D
std::list<node*>* node::get_in_edges()
{
	return m_in_edges;
}

//:D
std::list<node*>* node::get_out_edges()
{
	return m_out_edges;
}

//:D
bool node::is_win()
{
	return m_tags.win_graph;
}

//:D
bool node::is_exp()
{
	return m_tags.explored;
}

//:D
unsigned int node::get_eff()
{
	return m_tags.past_min_effort;
}

//:D
unsigned int node::get_pos()
{
	return m_tags.pos;
}

//:D
unsigned int node::get_mov()
{
	return m_tags.past_movement;
}
}


