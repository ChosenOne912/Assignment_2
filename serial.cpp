#include <sys/time.h>
#include <math.h>

#include <iostream>
#include <sstream>
#include <iomanip>

#include <cstring>

#include <fstream>
#include <vector>

/**
	This function reads a matrix in from a text file

	@param input The input file containing the matrix values
	@param input_vector A vector to store the matrix values in
**/
void parse_file(const std::string &input, std::vector<double> &input_vector) {

	std::ifstream fin(input);
	int size = 0;
	double value = 0.0;

	fin >> size;
	input_vector.resize((size*size), 0.0);

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			fin >> value;
			input_vector[(i*size)+j] = value;
		}
	}

	fin.close();
}

/**
	This function writes matrix values to a text file

	@param output The name of the output text file
	@param size The size of the matrix to include in the file
	@param output_vector A vector containing the matrix values to write to the file
**/
void write_file(const std::string &output, int size, std::vector<double> output_vector) {

	std::ofstream fout(output);

	fout << size;

	for(std::vector<double>::iterator iter = output_vector.begin(); iter != output_vector.end(); ++iter){
		fout << " " << *iter;
	}

	fout.close();
}

/**
	This function reads matrices from text files, multiplies them serially, and
	then writes the result out to a text files

	@param input1 The first text file with matrix values
	@param input2 The second text file with matrix values
	@param ouput The output text file to write the results too 
**/
void multiply(const std::string &input1, const std::string &input2, const std::string &output) {

	int size = 0;
	std::vector<double> input_vector1;
	std::vector<double> input_vector2;
	std::vector<double> output_vector;

	parse_file(input1, input_vector1);
	parse_file(input2, input_vector2);

	size = (int) sqrt(input_vector1.size());
	output_vector.resize((size*size), 0.0);

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			double sum = 0.0;
			for(int k = 0; k < size; k++){
				sum += (input_vector1[(i*size)+k]*input_vector2[(k*size)+j]);
			}
			output_vector[(i*size)+j] = sum;
		}
	}

	write_file(output, size, output_vector);
}

void usage(const char *file_name) {
	std::cout << "Serial Matrix Multiplication." << std::endl << std::endl;

	std::cout << "Usage:  " << file_name << " input1 input2 output" << std::endl;
	std::cout << "  input1 * input2 = output" << std::endl;
}

bool parse_args(int argc, char *argv[], std::string &input1, std::string &input2, std::string &output) {
	input1.clear();
	input2.clear();
	output.clear();

	int ii=1;
	while(ii < argc) {
		if((strcmp(argv[ii], "-h") == 0) || (strcmp(argv[ii], "--help") == 0)) {
			usage(argv[0]);

			return false;
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
	std::string input1, input2, output;

	if(parse_args(argc, argv, input1, input2, output)) {
		struct timeval start_tv, end_tv;

		gettimeofday(&start_tv, NULL);
		multiply(input1, input2, output);
		gettimeofday(&end_tv, NULL);

		long double runtime = ((end_tv.tv_sec - start_tv.tv_sec)*(1000000.0L) + (end_tv.tv_usec - start_tv.tv_usec))/(1000.0L);

		std::cout << std::setprecision(17);
		std::cout << "Run Time: " << runtime << std::endl;
	}

	return 0;
}
