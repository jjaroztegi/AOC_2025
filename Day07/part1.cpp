#include <print>
#include <set>
#include <string>
#include <vector>

#include "common.h"

int count_splits(const std::vector<std::string>& manifold) {
  int rows = manifold.size();
  int cols = manifold[0].size();

  std::set<int> current_beams;
  int split_count = 0;

  for (int c = 0; c < cols; c++) {
    if (manifold[0][c] == 'S') {
      current_beams.insert(c);
      break;
    }
  }

  for (int r = 0; r < rows; r++) {
    std::set<int> next_beams;

    for (int c : current_beams) {
      char cell = manifold[r][c];

      if (cell == '^') {
        split_count++;

        if (c - 1 >= 0) next_beams.insert(c - 1);
        if (c + 1 < cols) next_beams.insert(c + 1);
      } else {
        next_beams.insert(c);
      }
    }

    current_beams = next_beams;
    if (current_beams.empty()) break;
  }

  return split_count;
}

int main() {
  auto input = load_input("test.txt");

  int splits = count_splits(input);
  std::println("Beam will be split {} times", splits);

  return 0;
}