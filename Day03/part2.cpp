#include <cstdint>
#include <fstream>
#include <print>
#include <vector>

#include "common.h"

struct MaxSelection {
  int value;
  size_t index;
};

MaxSelection find_max_suffix(std::vector<int>& digits, size_t start,
                             size_t end) {
  MaxSelection result{digits[start], start};
  for (size_t i = start + 1; i <= end; i++) {
    if (digits[i] > result.value) {
      result.value = digits[i];
      result.index = i;
    }
  }
  return result;
}

// Largest 12 digit number without rearrangement
uint64_t find_largest_joltage(std::vector<int>& digits) {
  uint64_t output = 0;
  size_t last_index = 0;

  for (int digit_num = 0; digit_num < 12; digit_num++) {
    size_t remaining = 12 - digit_num - 1;
    size_t end = digits.size() - 1 - remaining;

    MaxSelection next_digit = find_max_suffix(digits, last_index, end);
    output = output * 10 + next_digit.value;
    last_index = next_digit.index + 1;
  }

  return output;
}

int main() {
  std::fstream input_file("test.txt");
  std::string line;

  uint64_t output_joltage = 0;

  while (std::getline(input_file, line)) {
    auto bank = parse_bank(line);
    output_joltage += find_largest_joltage(bank);
  }

  std::println("Total output joltage is {}", output_joltage);
}
