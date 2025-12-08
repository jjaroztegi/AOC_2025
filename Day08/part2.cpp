#include <algorithm>
#include <print>
#include <unordered_map>
#include <vector>

#include "common.h"

int connect_boxes(size_t num_boxes, const std::vector<BoxPair>& pairs,
                  const std::vector<Box>& input) {
  std::vector<size_t> parent(num_boxes);
  std::vector<size_t> rank(num_boxes, 0);
  for (size_t i = 0; i < num_boxes; ++i) {
    parent[i] = i;
  }

  size_t circuits = num_boxes;
  BoxPair last_connection;

  for (size_t i = 0; i < pairs.size() && circuits > 1; ++i) {
    if (unite(parent, rank, pairs[i].box1, pairs[i].box2)) {
      circuits--;
      last_connection = pairs[i];
    }
  }

  int result = input[last_connection.box1].x * input[last_connection.box2].x;
  return result;
}

int main() {
  auto input = load_input("test.txt");

  std::vector<BoxPair> pairs;
  for (size_t i = 0; i < input.size(); i++) {
    for (size_t j = i + 1; j < input.size(); j++) {
      if (i == j) continue;
      auto dist = distance(input[i], input[j]);
      pairs.push_back({i, j, dist});
    }
  }
  std::sort(pairs.begin(), pairs.end(), compare_dist);

  int result = connect_boxes(input.size(), pairs, input);

  std::println(
      "Multiplication of the X coordinates of last 1 junction boxes is {}",
      result);
  return 0;
}