#pragma once

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

struct Range {
  uint64_t start;
  uint64_t end;
};

struct InputData {
  std::vector<Range> ranges;
  std::vector<uint64_t> ids;
};

// "a-b" into a Range
inline Range parse_range_line(const std::string& line) {
  auto dash_pos = line.find('-');
  uint64_t first_id = std::stoull(line.substr(0, dash_pos));
  uint64_t last_id = std::stoull(line.substr(dash_pos + 1));
  return {first_id, last_id};
}

inline InputData load_input(const std::string& filename) {
  std::fstream file(filename);
  std::string line;
  InputData data;

  // First section: ranges
  while (std::getline(file, line)) {
    if (line.empty()) break;
    data.ranges.push_back(parse_range_line(line));
  }

  // Second section: ids
  while (std::getline(file, line)) {
    if (!line.empty()) data.ids.push_back(std::stoull(line));
  }

  return data;
}