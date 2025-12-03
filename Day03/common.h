#pragma once

#include <fstream>
#include <string>
#include <vector>

inline std::vector<int> parse_bank(const std::string& line) {
  std::vector<int> bank(line.size());
  for (size_t i = 0; i < line.size(); ++i) {
    bank[i] = line[i] - '0';
  }
  return bank;
}
