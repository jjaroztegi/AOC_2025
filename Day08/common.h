#pragma once

#include <cmath>
#include <fstream>
#include <vector>

constexpr int NUM_PAIRS = 1000;

struct Box {
  int x;
  int y;
  int z;
};

struct BoxPair {
  size_t box1;
  size_t box2;
  double distance;
};

inline size_t find_parent(std::vector<size_t>& parent, size_t x) {
  if (parent[x] != x) {
    parent[x] = find_parent(parent, parent[x]);
  }
  return parent[x];
}

inline bool unite(std::vector<size_t>& parent, std::vector<size_t>& rank, size_t x,
           size_t y) {
  size_t root_x = find_parent(parent, x);
  size_t root_y = find_parent(parent, y);

  if (root_x == root_y) {
    return false;
  }

  if (rank[root_x] < rank[root_y]) {
    parent[root_x] = root_y;
  } else if (rank[root_x] > rank[root_y]) {
    parent[root_y] = root_x;
  } else {
    parent[root_y] = root_x;
    rank[root_x]++;
  }
  return true;
}

inline Box parse_coordinates(const std::string& line) {
  auto c1 = line.find(',');
  auto c2 = line.find(',', c1 + 1);
  int x = std::stoi(line.substr(0, c1));
  int y = std::stoi(line.substr(c1 + 1, c2 - (c1 + 1)));
  int z = std::stoi(line.substr(c2 + 1));
  return {x, y, z};
}

inline std::vector<Box> load_input(const std::string& filename) {
  std::ifstream file(filename);
  std::string line;
  std::vector<Box> box_positions;

  while (std::getline(file, line)) {
    auto box = parse_coordinates(line);
    box_positions.push_back(box);
  }

  return box_positions;
}

inline double distance(const Box& p, const Box& q) {
  double dx = p.x - q.x;
  double dy = p.y - q.y;
  double dz = p.z - q.z;
  return std::sqrt(dx * dx + dy * dy + dz * dz);
}

inline bool compare_dist(const BoxPair& a, const BoxPair& b) {
  return a.distance < b.distance;
}
