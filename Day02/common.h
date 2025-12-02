#pragma once

#include <fstream>
#include <ranges>
#include <string>

struct Range {
  long long start;
  long long end;
};

inline std::vector<Range> parse_line(const std::string& line) {
  std::vector<Range> ids_ranges;

  for (auto token : std::views::split(line, ',')) {
    std::string pair(token.begin(), token.end());

    auto dash_pos = pair.find('-');

    long long first_id = std::stoll(pair.substr(0, dash_pos));
    long long last_id = std::stoll(pair.substr(dash_pos + 1));

    ids_ranges.push_back({first_id, last_id});
  }
  return ids_ranges;
}
