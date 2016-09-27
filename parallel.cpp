#include <sys/time.h>

#include <iostream>
#include <sstream>
#include <iomanip>

#include <limits>

#include <cstring>

// TODO: implement this function
void multiply(const std::string &input1, const std::string &input2, const std::string &output, unsigned int threads) {
	
}

void usage(const char *file_name) {
	std::cout << "Parallel Matrix Multiplication." << std::endl << std::endl;
	
	std::cout << "Usage:  " << file_name << " [--threads n] input1 input2 output" << std::endl;
	std::cout << "  --threads  number of threads to use, default 2" << std::endl;
	std::cout << "  input1 * input2 = output" << std::endl;
}

bool parse_args(int argc, char *argv[], unsigned int &threads, std::string &input1, std::string &input2, std::string &output) {
	threads = 2;
	input1.clear();
	input2.clear();
	output.clear();
	
	int ii=1;
	while(ii < argc) {
		if((strcmp(argv[ii], "-h") == 0) || (strcmp(argv[ii], "--help") == 0)) {
			usage(argv[0]);
			
			return false;
		}
		else if(strcmp(argv[ii], "--threads") == 0) {
			ii++;
			if(ii >= argc) {
				std::cerr << "Option " << argv[ii-1] << " requires an argument." << std::endl << std::endl;
				usage(argv[0]);
				
				return false;
			}
			
			std::istringstream iss(argv[ii]);
			iss >> threads;
			
			if(iss.bad() || iss.fail() || !iss.eof()) {
				if(threads == std::numeric_limits<unsigned int>::max()) {
					std::cerr << "Number of threads specified exceeds maximum allowed value." << std::endl << std::endl;
					usage(argv[0]);
				
					return false;
				}
				else {
					std::cerr << "Option " << argv[ii-1] << " requires a positive integer value." << std::endl << std::endl;
					usage(argv[0]);
					
					return false;
				}
			}
			else if(threads == 0) {
				std::cerr << "Option " << argv[ii-1] << " requires a positive integer value." << std::endl << std::endl;
				usage(argv[0]);
				
				return false;
			}
		}
		else if(input1.empty()) {
			input1.assign(argv[ii]);
		}
		else if(input2.empty()) {
			input2.assign(argv[ii]);
		}
		else if(output.empty()) {
			output.assign(argv[ii]);
		}
		else {
			std::cerr << "Unrecognized input option " << argv[ii] << std::endl << std::endl;
			usage(argv[0]);
			
			return false;
		}
		
		ii++;
	}
	
	if(input1.empty()) {
		std::cerr << "No files specified." << std::endl << std::endl;
		usage(argv[0]);
		
		return false;
	}
	else if(input2.empty()) {
		std::cerr << "Missing second input file and output file." << std::endl << std::endl;
		usage(argv[0]);
		
		return false;
	}
	else if(output.empty()) {
		std::cerr << "Missing output file." << std::endl << std::endl;
		usage(argv[0]);
		
		return false;
	}
	
	return true;
}

int main(int argc, char *argv[]) {
	unsigned int threads;
	std::string input1, input2, output;
	
	if(parse_args(argc, argv, threads, input1, input2, output)) {
		struct timeval start_tv, end_tv;
		
		gettimeofday(&start_tv, NULL);
		multiply(input1, input2, output, threads);
		gettimeofday(&end_tv, NULL);
		
		long double runtime = ((end_tv.tv_sec - start_tv.tv_sec)*(1000000.0L) + (end_tv.tv_usec - start_tv.tv_usec))/(1000.0L);
		
		std::cout << std::setprecision(17);
		std::cout << "Run Time: " << runtime << std::endl;
	}
	
	return 0;
}
