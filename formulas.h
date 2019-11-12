#ifndef FORMULAS_H
#define FORMULAS_H
#include "colors.h"
#include <string>
#include <iomanip>
#include <cmath>

void velocity(double, double, std::string, std::string);
void acceleration(double, double, std::string, std::string);
void newton(double, double, std::string, std::string);
void weight(double, double, std::string);
void momentum(double, double, std::string);
void velocity_2(double, double, double, std::string);
void position(double, double, double, double, std::string);
void velocity_squared(double, double, double, double, std::string);
void avg_velocity(double, double, std::string);

void velocity(double s, double t, std::string s_unit, std::string t_unit) {
  double v = s / t;
  change_color(33);
  std::cout << std::fixed<< std::setprecision(4) << "The change in position is " << s << " " << s_unit << ". The change in time is " << t << " " << t_unit << ". The velocity is " << v << " " << s_unit << "/" << t_unit << "." << std::endl;
  reset_color();
}

void acceleration(double v, double t, std::string v_unit, std::string t_unit) {
  double a = v / t;
  change_color(33);
  std::cout << std::fixed << std::setprecision(4) << "The change in velocity is " << v << " " << v_unit << ". The change in time is " << t << " " << t_unit << ". The acceleration is " << a << " " << v_unit << "/" << t_unit << "." << std::endl;
  reset_color();
}

void newton(double m, double a, std::string m_unit, std::string a_unit) {
  double f = m * a;
  change_color(33);
  std::cout << std::fixed << std::setprecision(4) << "The mass is " << m << " " << m_unit << ". The acceleration is " << a << " " << a_unit << ". The force is " << f << " " << m_unit << "*" << a_unit << "." << std::endl;
  reset_color();
}

void weight(double m, double g, std::string unit) {
  double w = m * g;
  change_color(33);
  std::cout << std::fixed << std::setprecision(4) << "The mass is " << m << ". The gravitational constant is " << g << ". The weight is " << w << " " << unit << "." << std::endl;
  reset_color();
}

void momentum(double m, double v, std::string unit) {
  double p = m * v;
  change_color(33);
  std::cout << std::fixed << std::setprecision(4) << "The mass is " << m << ". The velocity is " << v << ". The momentum is " << p << " " << unit << "." << std::endl;
  reset_color();
}

void velocity_2(double v0, double a, double t, std::string unit) {
  double v = v0 + a * t;
  change_color(96);
  std::cout << std::fixed << std::setprecision(4) << "The initial velocity is " << v0 << ". The acceleration is " << a << ". The change in time is " << t << ". The final velocity is " << v << " " << unit << "." << std::endl;
  reset_color();
}

void position(double s0, double v0, double t, double a, std::string unit) {
  double s = s0 + v0 * t + 0.5 * a * std::pow(t, 2);
  change_color(96);
  std::cout << std::fixed << std::setprecision(4) << "The initial position is " << s0 << ". The initial velocity is " << v0 << ". The change in time is " << t << ". The acceleration is " << a << ". The final position is " << s << " " << unit << "." << std::endl;
  reset_color();
}

void velocity_squared(double v0, double a, double s, double s0, std::string unit) {
  double v2 = std::pow(v0, 2) + 2 * a * (s - s0);
  change_color(96);
  std::cout << std::fixed << std::setprecision(4) << "The initial velocity is " << v0 << ". The acceleration is " << a << ". The final position is " << s << ". The initial position is " << s0 << ". The velocity squared is " << v2 << " " << unit << "." << std::endl;
  reset_color();
}

void avg_velocity(double v, double v0, std::string unit) {
  double v_bar = 0.5 * (v + v0);
  change_color(96);
  std::cout << std::fixed << std::setprecision(4) << "The final velocity is " << v << " " << unit << ". The initial velocity is " << v0 << " " << unit << ". The average velocity is " << v_bar << " " << unit << "." << std::endl;
  reset_color();
}
#endif