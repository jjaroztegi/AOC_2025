#include <fstream>
#include <print>
#include <vector>

#include "common.h"

// Largest two digit number without rearrangement
int find_largest_joltage(std::vector<int>& digits) {
  int largest = 0;
  int second_largest = 0;
  size_t index = 0;
  for (size_t i = 0; i < digits.size() - 1; i++) {
    if (digits[i] > largest) {
      largest = digits[i];
      index = i;
    }
  };
  for (size_t i = index + 1; i < digits.size(); i++) {
    if (digits[i] > second_largest) {
      second_largest = digits[i];
    }
  }
  return 10 * largest + second_largest;
}

int main() {
  std::fstream input_file("test.txt");
  std::string line;

  int output_joltage = 0;

  while (std::getline(input_file, line)) {
    auto bank = parse_bank(line);
    output_joltage += find_largest_joltage(bank);
  }

  std::println("Total output joltage is {}", output_joltage);
}
