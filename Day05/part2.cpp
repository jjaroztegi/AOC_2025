#include <algorithm>
#include <print>

#include "common.h"

bool intersect_ranges(Range& current, const Range& new_range) {
  if (new_range.start <= current.end) {
    current.end = current.end > new_range.end ? current.end : new_range.end;
    return true;
  } else {
    current.start = new_range.start;
    current.end = new_range.end;
  }
  return false;
}

bool compare_ranges(const Range& a, const Range& b) {
  return a.start < b.start;
}

int main() {
  auto input = load_input("test.txt");

  std::sort(input.ranges.begin(), input.ranges.end(), compare_ranges);

  uint64_t total_fresh_ids = 0;
  Range current = input.ranges[0];
  for (auto r : input.ranges) {
    uint64_t buff = current.end - current.start + 1;
    if (!intersect_ranges(current, r)) {
      total_fresh_ids += buff;
    }
  }
  total_fresh_ids += current.end - current.start + 1;
  std::println("{} ingredients are considered fresh.", total_fresh_ids);
}