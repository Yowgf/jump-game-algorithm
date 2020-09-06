// ALG1-TP1 project tester
// Time complexity
// =========================================
//
// Description:
// Measures time complexity of the algorithm
/////////////////////////////////////////////////

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

// First, generate random entries, and then run
//   each configuration 10 times, and output
//   each configuration's mean to a csv file.
//
int main() {
	// For string manipulations
	std::stringstream ss;

	// For time measures
	clock_t t;

	std::fstream test_file;
	std::fstream output_csv;
	std::string test_file_name("cur_test");
	std::string output_csv_name("times.csv");

	std::string test_command((std::string("tp1.exe ") += test_file_name) += " >nul");
	std::string del_command(std::string("del ") += test_file_name);

	std::cout << "Test command = " << test_command << std::endl;

	output_csv.open(output_csv_name.c_str(), std::fstream::out | std::fstream::trunc);
	if(!output_csv.is_open())
		throw std::runtime_error("Unable to open file");

	// Initializing random number generator
	srand(time(NULL));

	unsigned int m = 0;
	unsigned int n = 0;
	unsigned int num_players = 11;
	unsigned int cur_pos = 0;
	unsigned int size = 1;
	unsigned int size_step = 2;
	unsigned int max_size = size * pow(size_step, 20);
	register unsigned int i = 0;
	register unsigned int j = 0;
	// Changing sizes
	for(size = 1; size <= max_size; size *= size_step) {
		test_file.open(test_file_name.c_str(), std::fstream::out | std::fstream::trunc);
		
		m = (unsigned int)sqrt(size);
		n = (unsigned int)sqrt(size);
		std::cout << "Creating new file" << std::endl;
		std::cout << "m = " << m << " n = " << n << std::endl;

		// Create file with right configuration
		// First, input m and n
		test_file << m << ' ' << n << '\n';

		// Then, the amount of players.
		test_file << num_players << '\n';
		
		// Then, the board
		for(i = 0; i < m; i++) {
			for(j = 0; j < n - 1; j++) {
				cur_pos = ((rand() * 1.0) / RAND_MAX) * m;
				test_file << cur_pos << ' ';
			}
			test_file << cur_pos << '\n';
		}

		// Then, the players
		for(i = 0; i < num_players; i++) {
			cur_pos = ((rand() * 1.0) / RAND_MAX) * m;
			test_file << cur_pos << ' ';
			cur_pos = ((rand() * 1.0) / RAND_MAX) * m;
			test_file << cur_pos << '\n';
		}

		// Close file, to truncate and let program open
		test_file.close();

		t = clock();
		// Run 10 times with each size
		for(i = 0; i < 10; i++) {
			system(test_command.c_str()); 
		}
		t = clock() - t;
		// Write mean to output csv
		output_csv << (int)(((float)t) / 10) << '\n';

	}

	if(test_file.is_open())
		test_file.close();

	if(output_csv.is_open())
		output_csv.close();

	system(del_command.c_str());

	return 0;
}
