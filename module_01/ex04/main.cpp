#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Error: 3 positional arguments required" << std::endl;
    return 1;
  }
  std::string filename(argv[1]);
  std::string oldString(argv[2]);
  std::string newString(argv[3]);

  std::ifstream iStream(filename.c_str());
  if (!iStream) {
    std::cerr << "Error: Unable to open file: " << filename << std::endl;
    return 1;
  }
  std::ofstream oStream((filename + ".replace").c_str());
  if (!iStream) {
    std::cerr << "Error: Unable to open file: " << filename + ".replace"
              << std::endl;
    return 1;
  }
  return 0;
}