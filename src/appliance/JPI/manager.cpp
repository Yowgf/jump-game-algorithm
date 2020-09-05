// ALG1-TP1 project appliance file
// JPI module
// Manager
// ===============================
//
// Description:
// Class that receives the board and players from
//   ~init~ class, and then executes the game
//   algorithm at a high level, delegating tasks
//   to ~Containers~ module.
/////////////////////////////////////////////////

#include "JPI/manager.hpp"

#include "Containers/bfs.hpp"

#include <iostream>
#include <stdexcept>

namespace JPI {

//:D
manager::manager(Containers::board* t_board, Containers::players* t_players)
{
	if(t_board == nullptr)
		throw std::invalid_argument("manager::manager t_board nullptr");
	if(t_players == nullptr)
		throw std::invalid_argument("manager::manager t_players nullptr");
	if(t_board->empty() || t_players->empty()) {
			print_result(nullptr, 0);
	}
	else {
		exec_alg(t_board, t_players);
		print_result(t_players->get_abs_winner(), t_board->get_finish_line()->get_eff());
	}
}

//:D
// While players not exhausted, do BFS search one by one.
void manager::exec_alg(Containers::board* t_board, Containers::players* t_players)
{
	// Useful variables
	Containers::player* l_cur_player = nullptr;
	Containers::node* l_finish_line = t_board->get_finish_line();
	// Set the first virtual effort to be really big,
	//   so that the first player to get to the finish
	//   may be declared a finalist.
	unsigned int l_cur_effort = -1;

	// Basically perform bfs algorithm.
	// Also, this loop manipulates the game's winners
	//std::cout << '\n';
	while(!t_players->empty()) {
		l_cur_player = t_players->pop_front();
		//std::cout << "Searching player " << l_cur_player->get_id() << "..." << std::endl;
		Containers::bfs(l_cur_player, t_board);
		//std::cout << "Searched player." << std::endl;

		// Checking if the current player got to the end.
		if(l_cur_player->is_finalist()) {
			//std::cout << "Player is finalist!" << std::endl;
			//std::cout << "Player final movement: " << l_cur_player->get_final_mov() << std::endl;
			// If he has gotten to the end with better effort, or
			//   if the movement to the last node before the
			//   finish line was smaller, this player has beaten
			//   everyone else!
			if(l_finish_line->get_eff() < l_cur_effort || 
					(
						l_finish_line->get_eff() == l_cur_effort &&
						l_cur_player->get_final_mov() < t_players->get_winner_mov()
					)
				) {
				t_players->clear_winners();
				//std::cout << "We have a new super winner!!!" << std::endl;
			}
			t_players->add_winner(l_cur_player);
		}
		l_cur_effort = t_board->get_finish_line()->get_eff();
	}

	// This basically finishes the algorithm.
	// A search for the winner with minimum id is also done
	//   in the function print_result.
}

//:D
void manager::print_result(Containers::player* t_winner, unsigned int t_last_effort)
{
	if(t_winner != nullptr) {
		// This will convert the id to a ascii char
		char l_winner = t_winner->get_id() + 65;
		std::cout << l_winner << '\n' << t_last_effort << '\n';
	}
	else {
		std::cout << "SEM VENCEDORES\n";
	}
}

}
