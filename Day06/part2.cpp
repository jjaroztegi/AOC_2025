#include <cstdint>
#include <fstream>
#include <print>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::ifstream file("test.txt");
  std::vector<std::string> lines;
  std::string line;

  while (std::getline(file, line)) {
    lines.push_back(line);
  }

  std::string symbol_line = lines.back();
  lines.pop_back();

  // Operators right to left
  std::stringstream ss_ops(symbol_line);
  std::vector<char> operators;
  char op;
  while (ss_ops >> op) {
    operators.push_back(op);
  }
  std::reverse(operators.begin(), operators.end());

  size_t max_len = 0;
  for (const auto& l : lines) {
    max_len = std::max(max_len, l.length());
  }

  // Pad with space
  for (auto& l : lines) {
    while (l.length() < max_len) {
      l += ' ';
    }
  }

  uint64_t grand_total = 0;
  size_t problem_idx = 0;

  int col = max_len - 1;
  while (col >= 0) {
    std::vector<uint64_t> nums;

    while (col >= 0) {
      std::string digit_column;

      for (const auto& l : lines) {
        if (l[col] != ' ') {
          digit_column += l[col];
        }
      }

      if (digit_column.empty()) {
        // All space column -> problem separator
        col--;
        break;
      }

      nums.insert(nums.begin(), std::stoull(digit_column));
      col--;
    }

    if (!nums.empty() && problem_idx < operators.size()) {
      char op = operators[problem_idx];
      uint64_t result = nums[0];

      for (size_t i = 1; i < nums.size(); i++) {
        if (op == '*') {
          result *= nums[i];
        } else {
          result += nums[i];
        }
      }

      grand_total += result;
      problem_idx++;
    }
  }

  std::println("Grand total found is {}", grand_total);
}