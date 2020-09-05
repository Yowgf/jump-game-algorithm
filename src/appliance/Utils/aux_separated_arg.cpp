// ALG1-TP1 project appliance file
// Utils module
// Auxiliary separated argument
// ============================
//
// Description:
// Class that facilitates argument passing
/////////////////////////////////////////////////

#include "Utils/aux_separated_arg.hpp"

namespace Utils {

//:D
aux_separated_arg::aux_separated_arg()
{
	board = new aux_matrix();
	players = new aux_matrix();
}

//:D
aux_separated_arg::~aux_separated_arg()
{
	// These are just the aux_matrices, not the actual
	//   board and players classes objects.
	delete board;
	delete players;
}

}


