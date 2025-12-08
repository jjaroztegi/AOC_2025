#include <algorithm>
#include <print>
#include <unordered_map>
#include <vector>

#include "common.h"

int connect_boxes(size_t num_boxes, const std::vector<BoxPair>& pairs,
                  size_t limit) {
  std::vector<size_t> parent(num_boxes);
  std::vector<size_t> rank(num_boxes, 0);
  for (size_t i = 0; i < num_boxes; ++i) {
    parent[i] = i;
  }

  for (size_t i = 0; i < limit && i < pairs.size(); ++i) {
    unite(parent, rank, pairs[i].box1, pairs[i].box2);
  }

  std::unordered_map<size_t, size_t> circuit_sizes;
  for (size_t i = 0; i < num_boxes; ++i) {
    circuit_sizes[find_parent(parent, i)]++;
  }

  std::vector<size_t> sizes;
  for (const auto& [root, size] : circuit_sizes) {
    sizes.push_back(size);
  }
  std::sort(sizes.begin(), sizes.end(), std::greater<size_t>());

  std::println("Top 3 circuit sizes: {}, {}, {}", sizes[0], sizes[1], sizes[2]);

  return sizes[0] * sizes[1] * sizes[2];
}

int main() {
  auto input = load_input("input.txt");

  std::vector<BoxPair> pairs;
  for (size_t i = 0; i < input.size(); i++) {
    for (size_t j = i + 1; j < input.size(); j++) {
      if (i == j) continue;
      auto dist = distance(input[i], input[j]);
      pairs.push_back({i, j, dist});
    }
  }
  std::sort(pairs.begin(), pairs.end(), compare_dist);

  int total_size = connect_boxes(input.size(), pairs, NUM_PAIRS);

  std::println("Multiplication of the size of the 3 largest circuits is {}",
               total_size);
  return 0;
}