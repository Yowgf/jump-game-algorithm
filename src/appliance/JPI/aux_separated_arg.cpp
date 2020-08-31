// ALG1-TP1 project appliance file
// JPI module
// Auxiliary separated argument
// ============================
//
// Description:
// Class that facilitates argument passing
/////////////////////////////////////////////////

#include "JPI/aux_separated_arg.hpp"

namespace JPI {

//~
aux_separated_arg::~aux_separated_arg()
{
	delete board;
	delete players;
}

}


