#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>

#include <random>

#include <string>

#include <limits>

#include <cerrno>
#include <cstdlib>
#include <cstring>

void usage(const char *file_name) {
	std::cout << "Create Matrix" << std::endl << std::endl;
	
	std::cout << "Usage:  " << file_name << " [-s/--size n] [-o/--output file]" << std::endl;
	std::cout << "  --size    size of desired square matrix, default 100" << std::endl;
	std::cout << "  --output  optional file to save output" << std::endl;
}

bool parse_args(int argc, char *argv[], unsigned int &size, std::string &output) {
	size = 100;
	output.clear();
	
	int ii=1;
	while(ii < argc) {
		if((strcmp(argv[ii], "-h") == 0) || (strcmp(argv[ii], "--help") == 0)) {
			usage(argv[0]);
			
			return false;
		}
		else if((strcmp(argv[ii], "-s") == 0) || (strcmp(argv[ii], "--size") == 0)) {
			ii++;
			if(ii >= argc) {
				std::cerr << "Option " << argv[ii-1] << " requires an argument." << std::endl << std::endl;
				usage(argv[0]);
				
				return false;
			}
			
			std::istringstream iss(argv[ii]);
			iss >> size;
			
			if(iss.bad() || iss.fail() || !iss.eof()) {
				if(size == std::numeric_limits<double>::max()) {
					std::cerr << "Size specified exceeds maximum allowed value." << std::endl << std::endl;
					usage(argv[0]);
				
					return false;
				}
				else {
					std::cerr << "Option " << argv[ii-1] << " requires an integer value." << std::endl << std::endl;
					usage(argv[0]);
					
					return false;
				}
			}
			else if(size == 0) {
				std::cerr << "Size must be a positive integer value." << std::endl << std::endl;
				usage(argv[0]);
			
				return false;
			}
		}
		else if((strcmp(argv[ii], "-o") == 0) || (strcmp(argv[ii], "--output") == 0)) {
			ii++;
			if(ii >= argc) {
				std::cerr << "Option " << argv[ii-1] << " requires an argument." << std::endl << std::endl;
				usage(argv[0]);
				
				return false;
			}
			
			output.assign(argv[ii]);
		}
		else {
			std::cerr << "Unrecognized input option " << argv[ii] << std::endl << std::endl;
			usage(argv[0]);
			
			return false;
		}
		
		ii++;
	}
	
	return true;
}

void create_matrix(unsigned int size, std::ostream &output) {
	std::random_device random;
	std::default_random_engine generator(random());
	
	double val;
	output << size;
	
	for(unsigned int ii=0; ii < size; ii++) {
		for(unsigned int jj=0; jj < size; jj++) {
			val = (generator() % 1000) / 100.0;
			output << " " << val;
		}
	}
}

int main(int argc, char *argv[]) {
	unsigned int size;
	std::string file_name;
	
	if(parse_args(argc, argv, size, file_name)) {
		if(file_name.empty()) {
			create_matrix(size, std::cout);
		}
		else {
			std::ofstream file(file_name.c_str());
			if(file) {
				create_matrix(size, file);
				
				if(file.bad()) {
					std::cerr <<  file_name << ": " << strerror(errno) << std::endl;
				}
			}
			else {
				std::cerr <<  file_name << ": " << strerror(errno) << std::endl;
			}
		}
	}
	
	return 0;
}
