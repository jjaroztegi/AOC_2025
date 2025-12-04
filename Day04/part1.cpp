#include <print>

#include "common.h"

int main() {
  auto grid = load_grid("test.txt");

  int valid_rolls = 0;
  for (int r = 0; r < (int)grid.size(); r++) {
    for (int c = 0; c < (int)grid[r].size(); c++) {
      if (grid[r][c] == '@') {
        if (count_adj(grid, r, c) < 4) {
          valid_rolls++;
        }
      }
    }
  }

  std::println("Accessible rolls by forklift: {}", valid_rolls);
}