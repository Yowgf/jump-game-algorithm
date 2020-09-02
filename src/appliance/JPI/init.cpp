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
init::init(int t_argc, char** t_argv)
{
	
	std::cout << "Vamos entrar na funcao!!!" << std::endl;
	
	std::list<std::string*>* all_entries = aux_read_entry_file(t_argc, t_argv);
	aux_separated_arg* separated_entries = aux_separate(all_entries);
	
	Containers::board* board = init_board(separated_entries->board);
	Containers::players* players = init_players(separated_entries->players);
	
	std::cout << "Initialized board and players!" << std::endl;

	delete separated_entries; // No need to keep memory allocated

	manager(board, players);

	delete players;
	delete board;

	std::cout << "Deleted everything!" << std::endl;
	std::cout << "Returning to main..." << std::endl;
}

//-
init::~init()
{}

//:D
Containers::board* init::init_board(aux_matrix* t_board_lines)
{
	return new Containers::board(t_board_lines);
}

//:D
Containers::players* init::init_players(aux_matrix* t_players_lines)
{
	return new Containers::players(t_players_lines);
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
	char char_medium[256];
	while(!entry_file.eof()) {
		entry_file.getline(char_medium, 256);
		if(char_medium[0] == '\0' || char_medium[0] == '\n')
			break;

		lines->push_back(new std::string(char_medium));
		std::cout << *(lines->back()) << std::endl;
	}

	std::cout << "Ended file reading..." << std::endl;

	entry_file.close();

	return lines;
}

//:D
aux_separated_arg*  init::aux_separate(std::list<std::string*>* t_lines)
{
	aux_separated_arg* sep_arg = new aux_separated_arg();
	aux_matrix* board = sep_arg->board;
	aux_matrix* players = sep_arg->players;

	if(board->entries == nullptr || players->entries == nullptr)
		throw std::invalid_argument("Aux_matrix entries not initialized");

	// Variables used to make transition
	unsigned int m = 0, n = 0, k = 0;
	std::stringstream ss;
	
	// Acquiring m and n
	ss.str(*(t_lines->front()));
	t_lines->pop_front();
	ss >> m >> n;
	board->m = m;
	board->n = n;

	ss.clear();

	// Acquiring k
	ss.str(*(t_lines->front()));
	t_lines->pop_front();
	ss >> k;
	players->m = k;
	players->n = k_board_dim;

	ss.clear();


	std::cout << "Starting to mess with matrices... " << std::endl;
	// Setting board strings
	std::list<std::string*>* local_entries = board->entries;
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
	local_entries = players->entries;
	local_it = local_entries->begin();
	lines_itf = lines_ite;
	std::advance(lines_ite, k);
	local_entries->splice(local_it, *t_lines, lines_itf, lines_ite);

	std::cout << "Players lines: " << local_entries->size() << std::endl;
	std::cout << "Lines left: " << t_lines->size() << std::endl;
	// Print players
	for(local_it = local_entries->begin(); local_it != local_entries->end(); local_it++) {
		std::cout << **local_it << std::endl;
	}
	
	delete t_lines;

	return sep_arg;
}

}
