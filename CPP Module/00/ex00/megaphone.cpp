#include <cstring>
#include <iostream>

void printToUpper(char *str) {
  for (int i = 0; str[i]; i++) {
    std::cout << static_cast<char>(std::toupper(str[i]));
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "BEEEEEP!!" << std::endl;
    return 0;
  }

  for (int i = 1; i < argc; i++) {
    printToUpper(argv[i]);
  }
  std::cout << std::endl;

  return 0;
}