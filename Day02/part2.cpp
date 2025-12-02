#include <cmath>
#include <print>
#include <vector>

#include "common.h"

// Inavlid ID is made only of some sequence of digits repeated at least twice
// N is made of a repeated block of digits if and only if:
// N ∈ { b * (10^(k*n) - 1) / (10^k - 1) : b ∈ ℕ, k ≥ 1, n ≥ 2 }
// and the base-10 length of b ≤ k
bool invalid_id(long long id) {
  std::string digits = std::to_string(id);
  int length = digits.size();

  for (int k = 1; k <= length / 2; k++) {
    // 10^k
    int pow10k = 1;
    for (int i = 0; i < k; i++) pow10k *= 10;

    int max_n = length / k;

    for (int n = 2; n <= max_n; n++) {
      // sum: (10^(k*n) - 1) / (10^k - 1)
      long long series = (pow(10LL, k * n) - 1) / (pow10k - 1);

      if (id % series != 0) continue;

      long long b = id / series;
      std::string b_digits = std::to_string(b);

      if ((int)b_digits.size() <= k) {
        return true;
      }
    }
  }
  return false;
}

long long find_invalid_ids(long long start, long long end) {
  long long count = 0;
  for (long long i = start; i <= end; i++) {
    if (invalid_id(i)) {
      count += i;
    }
  }

  return count;
}

int main() {
  std::fstream input_file("test.txt");
  std::string line;
  std::getline(input_file, line);

  auto ranges = parse_line(line);

  long long invalid_count = 0;
  for (auto& r : ranges) {
    invalid_count += find_invalid_ids(r.start, r.end);
  }
  std::println("Sum of invalid ids: {}", invalid_count);
}