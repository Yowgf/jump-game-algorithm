// ALG1-TP1 project appliance file
// Utils module
// Utils general library
// ===============================
//
// Description:
// Universal Utils functions
/////////////////////////////////////////////////

#include "Utils/Utils.hpp"

#include <iostream>
#include <stdexcept>
#include <sstream>

namespace Utils {

//:D
std::list<unsigned int>* aux_str_to_int(aux_matrix* t_uncut_strs)
{
	if(t_uncut_strs == nullptr)
		throw std::invalid_argument("aux_str_to_int nullptr t_uncut_strs.");

	// Useful variables
	unsigned int l_cur_int = 0;
	std::stringstream l_ss;
	std::list<std::string*>* l_str_lines = t_uncut_strs->entries;

	//std::cout << "l_str_lines size " << l_str_lines->size() << std::endl;
	// Return variable, integer representation of entry strings
	std::list<unsigned int>* int_rep = new std::list<unsigned int>();
	
	// Extracting integer by integer
	while(!l_str_lines->empty()) {
		l_ss.str(*(l_str_lines->front()));
		while(!l_ss.eof()){
			l_ss >> l_cur_int;
			int_rep->push_back(l_cur_int);
		}
		l_ss.clear();
		delete l_str_lines->front();
		l_str_lines->pop_front();
	}

	return int_rep;
}

}
