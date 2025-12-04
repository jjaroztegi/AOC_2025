#pragma once

#include <fstream>
#include <string>
#include <vector>

// Arrays for 8-direction movement
constexpr int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Count adjacent '@'
inline int count_adj(const std::vector<std::string>& grid, int row, int col) {
  int rows = grid.size();
  int cols = grid[0].size();
  int count = 0;

  for (int k = 0; k < 8; k++) {
    int r = row + dr[k];
    int c = col + dc[k];

    if (0 <= r && r < rows && 0 <= c && c < cols) {
      if (grid[r][c] == '@') count++;
    }
  }

  return count;
}

// Load grid from file
inline std::vector<std::string> load_grid(const std::string& filename) {
  std::fstream file(filename);
  std::string line;
  std::vector<std::string> grid;

  while (std::getline(file, line)) {
    grid.push_back(line);
  }

  return grid;
}
