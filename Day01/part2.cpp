#include <print>

#include "common.h"

void rotate(int& pos, Move move, size_t& password) {
  if (move.dir == 'L') {
    for (int i = 0; i < move.num; i++) {
      pos = (pos - 1 + DIAL_SIZE) % DIAL_SIZE;
      if (is_zero(pos)) {
        password++;
      }
    }
  } else if (move.dir == 'R') {
    for (int i = 0; i < move.num; i++) {
      pos = (pos + 1 + DIAL_SIZE) % DIAL_SIZE;
      if (is_zero(pos)) {
        password++;
      }
    }
  }
}

int main() {
  int dial_pos = START_POS;
  size_t password = 0;

  std::fstream input_file("input.txt");
  std::string line;
  while (std::getline(input_file, line)) {
    auto move = decode_move(line);
    rotate(dial_pos, move, password);
  }

  std::println("Password: {}", password);
}