// ALG1-TP1 project appliance file
// Utils module
// Auxiliary matrix
// ===============================
//
// Description:
// Class that facilitates argument passing
/////////////////////////////////////////////////

#include "Utils/aux_matrix.hpp"

#include <iostream>

namespace Utils {

//:D
aux_matrix::aux_matrix()
{
	m = 0;
	n = 0;
	entries = new std::list<std::string*>();
}

//:D
aux_matrix::~aux_matrix()
{
	while(!entries->empty()){
		//std::cout << "Deleting entry " << std::endl << *(entries->front()) << std::endl;
		delete entries->front();
		entries->pop_front();
	}
	delete entries;
}

}

