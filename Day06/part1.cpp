#include <cstdint>
#include <fstream>
#include <print>
#include <sstream>
#include <string>
#include <vector>

struct Problem {
  std::vector<std::vector<int>> numbers;
  std::vector<char> symbols;
};

Problem load_input(const std::string& filename) {
  std::ifstream file(filename);

  Problem problem;

  std::vector<std::vector<int>> rows;
  std::vector<std::string> lines;
  std::string line;

  while (std::getline(file, line)) {
    lines.push_back(line);
  }

  std::string symbols_line = lines.back();
  lines.pop_back();

  std::vector<char> symbols;
  std::stringstream ss_symbol(symbols_line);
  char symbol;
  while (ss_symbol >> symbol) {
    symbols.push_back(symbol);
  }

  for (auto i : lines) {
    std::stringstream ss(i);
    std::vector<int> row;
    int x;
    while (ss >> x) {
      row.push_back(x);
    }
    rows.push_back(row);
  }

  problem.numbers = rows;
  problem.symbols = symbols;

  return problem;
}

int main() {
  auto input = load_input("test.txt");

  uint64_t grand_total = 0;

  size_t num_columns = input.symbols.size();
  size_t num_rows = input.numbers.size();

  for (size_t col = 0; col < num_columns; col++) {
    char op = input.symbols[col];
    uint64_t buff = (op == '*') ? 1 : 0;

    for (size_t row = 0; row < num_rows; row++) {
      uint64_t val = input.numbers[row][col];

      if (op == '*') {
        buff *= val;
      } else {
        buff += val;
      }
    }
    grand_total += buff;
  }

  std::println("Grand total found is {}", grand_total);
}