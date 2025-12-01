#pragma once

#include <fstream>
#include <string>

constexpr int DIAL_SIZE = 100;
constexpr int START_POS = 50;

struct Move {
  char dir;
  int num;
};

inline Move decode_move(const std::string& move) {
  return {move[0], std::stoi(move.substr(1))};
}

inline bool is_zero(int pos) { return pos == 0; }
