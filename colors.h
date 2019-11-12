#ifndef COLORS_H
#define COLORS_H

//Function prototypes
void change_color(int);
void reset_color();

void change_color(int color) {
  std::cout << "\x1b[" << color << ";1m";
}

void reset_color() {
  std::cout << "\x1b[0m";
}
#endif