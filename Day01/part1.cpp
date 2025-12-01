#include <print>

#include "common.h"

void rotate(int& pos, Move move) {
  if (move.dir == 'L') {
    pos = (pos - move.num + DIAL_SIZE) % DIAL_SIZE;
  } else if (move.dir == 'R') {
    pos = (pos + move.num + DIAL_SIZE) % DIAL_SIZE;
  }
}

int main() {
  int dial_pos = START_POS;
  size_t password = 0;

  std::fstream input_file("input.txt");
  std::string line;
  while (std::getline(input_file, line)) {
    auto move = decode_move(line);
    rotate(dial_pos, move);
    if (is_zero(dial_pos)) {
      password++;
    }
  }

  std::println("Password: {}", password);
}