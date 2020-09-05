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

#include "JPI/manager.hpp"

#include <exception>
#include <fstream>
#include <sstream>

namespace JPI {

//:D
init::init(int t_argc, char** t_argv)
{
	std::list<std::string*>* all_entries = aux_read_entry_file(t_argc, t_argv);
	Utils::aux_separated_arg* separated_entries = aux_separate(all_entries);

	Containers::board* board = init_board(separated_entries->board);
	Containers::players* players = init_players(separated_entries->players);

	delete separated_entries; // No need to keep memory allocated

	manager(board, players);

	delete players;
	delete board;

}

//:D
Containers::board* init::init_board(Utils::aux_matrix* t_board_lines)
{
	return new Containers::board(t_board_lines);
}

//:D
Containers::players* init::init_players(Utils::aux_matrix* t_players_lines)
{
	return new Containers::players(t_players_lines);
}

//:D
std::list<std::string*>* init::aux_read_entry_file(int t_argc, char** t_argv)
{
	// Guarantees that t_argv[1] is in range.
	if(t_argc != 2)
		throw std::invalid_argument(std::to_string(t_argc - 1) +=
			" arguments provided\nProgram usage: $(program) $(input_file).\n");

	char* file_name = t_argv[1];
	std::fstream entry_file(file_name);

	if(!entry_file)
		throw std::invalid_argument(std::string("Unable to open file ") += file_name);

	// Initialize list of strings
	std::list<std::string*>* lines = new std::list<std::string*>();

	// Actual file reading (line by line)
	char char_medium[4096];
	while(!entry_file.eof()) {
		entry_file.getline(char_medium, 4096);
		if(char_medium[0] == '\0' || char_medium[0] == '\n')
			break;

		lines->push_back(new std::string(char_medium));
	}

	entry_file.close();

	return lines;
}

//:D
Utils::aux_separated_arg*  init::aux_separate(std::list<std::string*>* t_lines)
{
	Utils::aux_separated_arg* sep_arg = new Utils::aux_separated_arg();
	Utils::aux_matrix* board = sep_arg->board;
	Utils::aux_matrix* players = sep_arg->players;

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

	// Setting board strings
	std::list<std::string*>* local_entries = board->entries;
	std::list<std::string*>::iterator local_it = local_entries->begin(),
                                    lines_itf = t_lines->begin(),
                                    lines_ite = t_lines->begin();
	std::advance(lines_ite, m);
	local_entries->splice(local_it, *t_lines, lines_itf, lines_ite);

	// Setting players strings
	local_entries = players->entries;
	local_it = local_entries->begin();
	lines_itf = lines_ite;
	std::advance(lines_ite, k);
	local_entries->splice(local_it, *t_lines, lines_itf, lines_ite);

	if(t_lines->size() > 0)
		throw std::runtime_error("init::aux_separated_arg t_lines not empty");

	delete t_lines;

	return sep_arg;
}

}
