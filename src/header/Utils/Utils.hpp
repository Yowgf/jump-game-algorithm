// ALG1-TP1 project header file
// Utils module
// Utils library
// ============================
//
// Description:
// Bounds the classes belonging to the Utils module
//   in this single header file.
// Also implements universal Utils functions
/////////////////////////////////////////////////

#ifndef UTILS_H
#define UTILS_H 1

#include "Utils/error.hpp"

#include "JPI/aux_matrix.hpp"

#include <list>

namespace Utils {

// Converts entries inside the aux_matrix to an 
//   integer representation, for use in
//   constructor of classes ~board~ and
//   ~players~.
std::list<unsigned int>* aux_str_to_int(JPI::aux_matrix*);

}

#endif
