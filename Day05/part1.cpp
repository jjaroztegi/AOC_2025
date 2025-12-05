#include <print>

#include "common.h"

bool is_valid_id(uint64_t num, uint64_t start, uint64_t end) {
  return num >= start && num <= end;
}

int main() {
  auto input = load_input("test.txt");

  int fresh_ids = 0;
  for (auto id : input.ids) {
    bool found = false;
    for (auto r : input.ranges) {
      if (is_valid_id(id, r.start, r.end)) {
        found = true;
        break;
      }
    }
    if (found) {
      fresh_ids++;
    }
  }
  std::println("Num of fresh IDs: {}", fresh_ids);
}