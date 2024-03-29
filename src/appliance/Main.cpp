// ALG1-TP1 project Main file
// Main function
// ============================
//
// Description:
// Direct interaction with the world outside of
//   the program, and transfers control to the
//   most high-level JPI module routine.
// Only parameter passing and simple exception
//   handling is done in the main function.
/////////////////////////////////////////////////

#include "Containers/Containers.hpp"
#include "JPI/JPI.hpp"
#include "Utils/Utils.hpp"

#include <stdexcept>

int main(int argc, char** argv)
{
	try {
		JPI::init(argc, argv);
	}
	catch(std::exception& e) {
		Utils::error(e, "Fatal");
	}

	return 0;
}
