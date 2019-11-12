#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include "formulas.h"
#include "input_validation.h"
#include "colors.h"

void showMenu();
void showMotionMenu();
void handleOption(std::string);
void handleMotionOption(std::string);

void showMenu() {
  change_color(33);
  std::cout << "It's physics time!" << std::endl;
  std::cout << "Option A: Velocity" << std::endl;
  std::cout << "Option B: Acceleration" << std::endl;
  std::cout << "Option C: Motion" << std::endl;
  std::cout << "Option D: Newton's 2nd Law" << std::endl;
  std::cout << "Option E: Weight" << std::endl;
  std::cout << "Option F: Momentum" << std::endl;
  std::cout << "Option G: Exit" << std::endl;
  std::cout << "Option H: Clear Screen" << std::endl;
  reset_color();
}

void showMotionMenu() {
  std::string option = "";
  do {
    change_color(96);
    std::cout << "It's motion time!" << std::endl;
    std::cout << "Option A: Solve for Velocity" << std::endl;
    std::cout << "Option B: Solve for Position" << std::endl;
    std::cout << "Option C: Solve for Velocity Squared" << std::endl;
    std::cout << "Option D: Solve for Average Velocity" << std::endl;
    std::cout << "Option E: Return" << std::endl;
    reset_color();
    std::cout << "Please enter an option: ";
    std::cin >> option;
    handleMotionOption(option);
  } while (option != "E" && option != "e");
}

void handleOption(std::string userOption) {
  if (userOption == "A" || userOption == "a") {
    double pos = 0.0;
    std::cout << "Please enter the change in postion (can be positive or negative)." << std::endl;
    pos = validateDouble(pos);
    std::string pos_unit;
    std::cout << "Please enter the unit for position." << std::endl;
    pos_unit = validateString(pos_unit);
    double time = 0.0;
    do {
      std::cout << "Please enter the change in time (must be a double greater than zero)." << std::endl;
      time = validateDouble(time);
      if (time <= 0) {
        std::cout << "Change in time must be a double greater than zero." << std::endl;
      }
    } while (time <= 0);
    std::string time_unit;
    std::cout << "Please enter the unit for time." << std::endl;
    time_unit = validateString(time_unit);
    velocity(pos, time, pos_unit, time_unit);
  }
  else if (userOption == "B" || userOption == "b") {
    double vel = 0.0;
    std::cout << "Please enter the change in velocity (can be positive or negative)." << std::endl;
    vel = validateDouble(vel);
    std::string vel_unit;
    std::cout << "Please enter the unit for velocity." << std::endl;
    vel_unit = validateString(vel_unit);
    double time = 0.0;
    do {
      std::cout << "Please enter the change in time (must be a double greater than zero)." << std::endl;
      time = validateDouble(time);
      if (time <= 0) {
        std::cout << "Change in time must be a double greater than zero." << std::endl;
      }
    } while(time <= 0);
    std::string time_unit;
    std::cout << "Please enter the unit for time." << std::endl;
    time_unit = validateString(time_unit);
    acceleration(vel, time, vel_unit, time_unit);
  }
  else if (userOption == "C" || userOption == "c") {
    showMotionMenu();
  }
  else if (userOption == "D" || userOption == "d") {
    double mass = 0.0;
    do {
      std::cout << "Please enter the mass (must be positive)." << std::endl;
      mass = validateDouble(mass);
      if (mass < 0) {
        std::cout << "Mass must be positive." << std::endl;
      }
    } while(mass < 0);
    std::string mass_unit;
    std::cout << "Please enter the unit for mass." << std::endl;
    mass_unit = validateString(mass_unit);
    double acc = 0.0;
    std::cout << "Please enter the acceleration." << std::endl;
    acc = validateDouble(acc);
    std::string acc_unit;
    std::cout << "Please enter the unit for acceleration." << std::endl;
    acc_unit = validateString(acc_unit);
    newton(mass, acc, mass_unit, acc_unit);
  }
  else if (userOption == "E" || userOption == "e") {
    double mass = 0.0;
    do {
      std::cout << "Please enter the mass (must be positive)." << std::endl;
      mass = validateDouble(mass);
      if (mass < 0) {
        std::cout << "Mass must be positive." << std::endl;
        }
      } while (mass < 0);
    double g = 0.0;
    std::cout << "Please enter the gravitational constant." << std::endl;
    g = validateDouble(g);
    std::string unit;
    std::cout << "Please enter the unit of the expected output." << std::endl;
    unit = validateString(unit);
    weight(mass, g, unit);
  }
  else if (userOption == "F" || userOption == "f") {
    double mass = 0.0;
    do {
      std::cout << "Please enter the mass (must be positive)." << std::endl;
      mass = validateDouble(mass);
      if (mass < 0) {
        std::cout << "Mass must be positive." << std::endl;
      }
    } while(mass < 0);
    double vel = 0.0;
    std::cout << "Please enter the velocity." << std::endl;
    vel = validateDouble(vel);
    std::string unit;
    std::cout << "Please enter the unit of the expected output." << std::endl;
    unit = validateString(unit);
    momentum(mass, vel, unit);
  }
  else if (userOption == "G" || userOption == "g") {
    std::cout << "Goodbye!" << std::endl;
  }
  else if (userOption == "H" || userOption == "h") {
    std::cout << "\x1b[2J\x1b[H";
  }
  else {
    std::cout << "Invalid option. Please try again." << std::endl;
  } 
}

void handleMotionOption(std::string userOption) {
  if (userOption == "A" || userOption == "a") {
    double v0 = 0.0;
    std::cout << "Please enter the initial velocity." << std::endl;
    v0 = validateDouble(v0);
    double a = 0.0;
    std::cout << "Please enter the acceleration." << std::endl;
    a = validateDouble(a);
    double time = 0.0;
    do {
      std::cout << "Please enter the change in time (must be positive)." << std::endl;
      time = validateDouble(time);
      if (time < 0) {
        std::cout << "Change in time must be positive." << std::endl;
      }
    } while (time < 0);
    std::string unit;
    std::cout << "Please enter the unit of the expected output." << std::endl;
    unit = validateString(unit);
    velocity_2(v0, a, time, unit);
  }
  else if (userOption == "B" || userOption == "b") {
    double s0 = 0.0;
    std::cout << "Please enter the initial position." << std::endl;
    s0 = validateDouble(s0);
    double v0 = 0.0;
    std::cout << "Please enter the initial velocity." << std::endl;
    v0 = validateDouble(v0);
    double time = 0.0;
    do {
      std::cout << "Please enter the change in time (must be positive)." << std::endl;
      time = validateDouble(time);
      if (time < 0) {
        std::cout << "Change in time must be positive." << std::endl;
      }
    } while(time < 0);
    double a = 0.0;
    std::cout << "Please enter the acceleration." << std::endl;
    a = validateDouble(a);
    std::string unit;
    std::cout << "Please enter the unit of the expected output." << std::endl;
    unit = validateString(unit);
    position(s0, v0, time, a, unit);
  }
  else if (userOption == "C" || userOption == "c") {
    double v0 = 0.0;
    std::cout << "Please enter the initial velocity." << std::endl;
    v0 = validateDouble(v0);
    double a = 0.0;
    std::cout << "Please enter the acceleration." << std::endl;
    a = validateDouble(a);
    double s = 0.0;
    std::cout << "Please enter the final position." << std::endl;
    s = validateDouble(s);
    double s0 = 0.0;
    std::cout << "Please enter the initial position." << std::endl;
    s0 = validateDouble(s0);
    std::string unit;
    std::cout << "Please enter the unit of the expected output." << std::endl;
    unit = validateString(unit);
    velocity_squared(v0, a, s, s0, unit);
  }
  else if (userOption == "D" || userOption == "d") {
    double v = 0.0;
    std::cout << "Please enter the final velocity." << std::endl;
    v = validateDouble(v);
    double v0 = 0.0;
    std::cout << "Please enter the initial velocity." << std::endl;
    v0 = validateDouble(v0);
    std::string unit;
    std::cout << "Please enter the unit of the expected output" << std::endl;
    unit = validateString(unit);
    avg_velocity(v, v0, unit);
  }
  else if (userOption == "E" || userOption == "e") {
    ;
  }
  else {
    std::cout << "Invalid option. Please try again." << std::endl;
  }
}
#endif