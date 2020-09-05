// ALG1-TP1 project header file
// Utils module
// Auxiliary matrix
// ============================
//
// Description:
// Class that facilitates argument passing
/////////////////////////////////////////////////

#ifndef AUX_MATRIX_H
#define AUX_MATRIX_H 1

#include <list>
#include <string>

namespace Utils {

class aux_matrix {
	public:
	unsigned int m, n;
	std::list<std::string*>* entries;

	aux_matrix();
	~aux_matrix();
};

}

#endif
