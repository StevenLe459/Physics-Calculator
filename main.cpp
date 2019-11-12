#include <iostream>
#include <string>
#include "functions.h"

int main() {
  std::string option;
  do {
    showMenu();
    std::cout << "Please enter your option: ";
    std::cin >> option;
    handleOption(option);
  } while (option != "G" && option != "g");
}