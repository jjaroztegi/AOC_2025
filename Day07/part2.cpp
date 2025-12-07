#include <print>
#include <string>
#include <vector>

#include "common.h"

long long count_timelines(const std::vector<std::string>& manifold) {
  int rows = manifold.size();
  int cols = manifold[0].size();

  std::vector<long long> timeline_counts(cols, 0);

  for (int c = 0; c < cols; ++c) {
    if (manifold[0][c] == 'S') {
      timeline_counts[c] = 1;
      break;
    }
  }

  for (int r = 0; r < rows; r++) {
    std::vector<long long> next_counts(cols, 0);

    for (int c = 0; c < cols; c++) {
      if (timeline_counts[c] == 0) continue;

      long long active_timelines = timeline_counts[c];
      char cell = manifold[r][c];

      if (cell == '^') {
        if (c - 1 >= 0) {
          next_counts[c - 1] += active_timelines;
        }
        if (c + 1 < cols) {
          next_counts[c + 1] += active_timelines;
        }
      } else {
        next_counts[c] += active_timelines;
      }
    }

    timeline_counts = next_counts;
  }

  long long total_timelines = 0;
  for (long long count : timeline_counts) {
    total_timelines += count;
  }

  return total_timelines;
}

int main() {
  auto input = load_input("test.txt");

  auto timelines = count_timelines(input);
  std::println("There will be {} different timelines", timelines);

  return 0;
}