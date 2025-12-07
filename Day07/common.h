#include <fstream>
#include <string>
#include <vector>

inline std::vector<std::string> load_input(const std::string& filename) {
  std::ifstream file(filename);
  std::vector<std::string> manifold;
  std::string line;

  while (std::getline(file, line)) {
    manifold.push_back(line);
  }
  return manifold;
}
