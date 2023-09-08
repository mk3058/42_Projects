#include <iostream>
#include <string>

int main() {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "< Addresses >" << std::endl;
  std::cout << "string: " << &str << "\nstringPTR: " << stringPTR
            << "\nstringREF: " << &stringREF << std::endl;

  std::cout << "\n< Values >" << std::endl;
  std::cout << "string: " << str << "\nstringPTR: " << *stringPTR
            << "\nstringREF: " << stringREF << std::endl;
}