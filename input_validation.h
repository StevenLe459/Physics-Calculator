#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H
#include <ios> //for ios_base::failure
#include <iostream>

//Function prototypes
int validateInt(int&);
char validateChar(char&);
double validateDouble(double&); 

template <typename T>
T getValidatedInput() {
	T result;
	std::cin >> result; //Gets input of type T
	//Check if cin failed or if user inputted other types with input
	if (std::cin.fail() || std::cin.get() != '\n') {
		//Clears fail message
		std::cin.clear();
		//Clears input stream
		while (std::cin.get() != '\n') {
			;
		}
		throw std::ios_base::failure("Invalid input.");
	}
	return result;
}

int validateInt(int& intInput) {
	while (true) {
		std::cout << "Enter an integer: ";
		try {
			intInput = getValidatedInput<int>();
		}
		catch (std::exception e) {
			std::cerr << e.what() << " Please enter an integer." << std::endl;
			continue;
		}
		break;
	}
	return intInput;
}

char validateChar(char& charInput) {
	while (true) {
		std::cout << "Enter a character: ";
		try {
			charInput = getValidatedInput<char>();
		}
		catch (std::exception e) {
			std::cerr << e.what() << " Please enter a character." << std::endl;
			continue;
		}
		break;
	}
	return charInput;
}

double validateDouble(double& doubleInput) {
	while (true) {
		std::cout << "Enter a double (with or without decimal points): ";
		try {
			doubleInput = getValidatedInput<double>();
		}
		catch (std::exception e) {
			std::cerr << e.what() << " Please enter a double (with or without decimal points).";
      std::cout << std::endl;		
      continue;
		} 
		break;
	}
	return doubleInput;
}

std::string validateString(std::string& stringInput) {
  while (true) {
    std::cout << "Enter a string: ";
		try {
			stringInput = getValidatedInput<std::string>();
		}
		catch (std::exception e) {
			std::cerr << e.what() << " Please enter a string.";
      std::cout << std::endl;			
      continue;
		} 
		break;
	}
	return stringInput;
}
#endif