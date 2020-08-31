// ALG1-TP1 project header file
// JPI module
// Auxiliary separated argument
// ============================
//
// Description:
// Class that facilitates argument passing
/////////////////////////////////////////////////

#ifndef AUX_SEPARATED_ARG
#define AUX_SEPARATED_ARG 1

#include "JPI/aux_matrix.hpp"

namespace JPI {

class aux_separated_arg {
public:
	aux_matrix* board;
	aux_matrix* players;

	~aux_separated_arg();
};

}

#endif
