#include <iostream>
#include "math_functions.h"

extern int globalVar; // Assume globalVar is defined in another source file

int main(int argc, char* argv[]) {
	if(argc!=3){
		std::cout << "Please enter 2 numbers." << std::endl;
		return 1;
	}
	int x = std::stoi(argv[1]);
	int y = std::stoi(argv[2]);
    std::cout << "Addition: " << add(x, y) << std::endl;
    std::cout << "Subtraction: " << subtract(x, y) << std::endl;
    return 0;
}
