#include <fstream>
#include <iostream>

std::string replace(std::string origin, std::string str1, std::string str2) {
  std::string::size_type n;

  n = origin.find(str1);

  while (n != std::string::npos) {
    origin.erase(n, str1.length());
    origin.insert(n, str2);
    n = origin.find(str1);
  }
  return (origin);
}

bool openFile(std::fstream &fstream, std::string filename,
              std::ios_base::openmode stream) {
  fstream.open(filename.c_str(), stream);
  if (!fstream.is_open()) {
    std::cout << "Cannot open file " << '"' + filename + '"' << std::endl;
    return (false);
  }
  return (true);
}

void freplace(std::string filename, std::string str1, std::string str2) {
  std::fstream origin;
  std::fstream target;
  std::string buffer;

  if (!openFile(origin, filename, std::ios::in) ||
      !openFile(target, filename + std::string(".replace"), std::ios::out))
    return;

  std::getline(origin, buffer);
  while (!buffer.empty()) {
    target << replace(buffer, str1, str2) << std::endl;
    buffer.erase();
    std::getline(origin, buffer);
  }
}

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cout << "Invalid number of arguments" << std::endl;
    return (0);
  }

  freplace(argv[1], argv[2], argv[3]);
}
