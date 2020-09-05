// ALG1-TP1 project header file
// Utils module
// Auxiliary separated argument
// ============================
//
// Description:
// Class that facilitates argument passing
/////////////////////////////////////////////////

#ifndef AUX_SEPARATED_ARG
#define AUX_SEPARATED_ARG 1

#include "Utils/aux_matrix.hpp"

namespace Utils {

class aux_separated_arg {
public:
	aux_matrix* board;
	aux_matrix* players;

	aux_separated_arg();
	~aux_separated_arg();
};

}

#endif
