#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("") {
    std::cout << "WrongAnimal Default Constructor Called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref) : type(ref.type) {
    std::cout << "WrongAnimal Copy Constructor Called!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &ref) {
    this->type = ref.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor Called!" << std::endl;
}

std::string WrongAnimal::getType() const { return this->type; }

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal's makeSound method called. Implementation class "
                 "required!"
              << std::endl;
}