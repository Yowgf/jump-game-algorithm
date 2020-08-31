// ALG1-TP1 project appliance file
// JPI module
// Initialization
// ===============================
//
// Description:
// Class that implements initialization routines,
//   creating objects such as current board and
//   players. It then hands these to the manager
//   class.
/////////////////////////////////////////////////

#include "JPI/init.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

namespace JPI {

//~
aux_matrix::~aux_matrix()
{
	delete entries;
}

//~
separated_arg::~separated_arg()
{
	delete board;
	delete players;
}

//-
init::init(int t_argc, char** t_argv)
{
	
	std::cout << "Vamos entrar na funcao!!!" << std::endl;
	
	std::list<std::string*>* all_entries = aux_read_entry_file(t_argc, t_argv);
	separated_arg* separated_entries = aux_separate(all_entries);
	
	Containers::board* board = init_board(separated_entries->board);
	Containers::players* players = init_players(separated_entries->players);
	
	delete separated_entries; // No need to keep memory allocated

	manager(board, players);

	delete players;
	delete board;
	
}

//-
init::~init()
{}

//-
Containers::board* init::init_board(aux_matrix*)
{
	return new Containers::board();
}

//-
Containers::players* init::init_players(aux_matrix*)
{
	return new Containers::players();
}

//:D
std::list<std::string*>* init::aux_read_entry_file(int t_argc, char** t_argv)
{
	// Guarantees that t_argv[1] is in range.
	if(t_argc <= 1 || t_argc >= 3)
		throw std::invalid_argument(std::to_string(t_argc - 1) += 
			" arguments provided\nProgram usage: $(program) $(input_file).\n");

	char* file_name = t_argv[1];
	std::cout << "file_name = " << file_name << std::endl;
	std::fstream entry_file(file_name);

	if(!entry_file)
		throw std::invalid_argument(std::string("Unable to open file ") += file_name);

	// Initialize list of strings
	std::list<std::string*>* lines = new std::list<std::string*>();

	// Actual file reading (line by line)
	register int i = 0;
	char char_medium[256];
	while(!entry_file.eof()) {
		entry_file.getline(char_medium, 256);
		if(char_medium[0] == '\0' || char_medium[0] == '\n')
			break;

		lines->push_back(new std::string(char_medium));
		std::cout << *(lines->back()) << std::endl;

		i++;
	}
	std::cout << "Ended file reading..." << std::endl;

	entry_file.close();

	return lines;
}

//:D
separated_arg*  init::aux_separate(std::list<std::string*>* t_lines)
{
	separated_arg* sep_arg = new separated_arg();

	sep_arg->board = new aux_matrix();
	sep_arg->players = new aux_matrix();

	// Variables used to make transition
	int m = 0, n = 0, k = 0;
	std::stringstream ss;
	
	// Acquiring m and n
	ss.str(*(t_lines->front()));
	t_lines->pop_front();
	ss >> m >> n;
	sep_arg->board->m = m;
	sep_arg->board->n = n;

	ss.clear();

	// Acquiring k
	ss.str(*(t_lines->front()));
	t_lines->pop_front();
	ss >> k;
	sep_arg->players->m = k;
	sep_arg->players->n = k_board_dim;

	ss.clear();


	std::cout << "Starting to mess with matrices... " << std::endl;
	// Setting board strings
	std::list<std::string*>* local_entries = sep_arg->board->entries;
	local_entries = new std::list<std::string*>();
	std::list<std::string*>::iterator local_it = local_entries->begin(),
                                    lines_itf = t_lines->begin(),
                                    lines_ite = t_lines->begin();
	std::advance(lines_ite, m);
	local_entries->splice(local_it, *t_lines, lines_itf, lines_ite);

	std::cout << "Board lines: " << local_entries->size() << std::endl;
	std::cout << "Lines left: " << t_lines->size() << std::endl;
	// Print board
	for(local_it = local_entries->begin(); local_it != local_entries->end(); local_it++) {
		std::cout << **local_it << std::endl;
	}
	
	// Setting players strings
	local_entries = sep_arg->players->entries;
	local_entries = new std::list<std::string*>();
	local_it = local_entries->begin();
	lines_itf = lines_ite;
	std::advance(lines_ite, k);
	local_entries->splice(local_it, *t_lines, lines_itf, lines_ite);

	std::cout << "Players lines: " << local_entries->size() << std::endl;
	std::cout << "Lines left: " << t_lines->size() << std::endl;
	// Print board
	for(local_it = local_entries->begin(); local_it != local_entries->end(); local_it++) {
		std::cout << **local_it << std::endl;
	}
	
	delete t_lines;

	return sep_arg;
}

}
