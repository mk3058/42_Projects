#include "AbstractAnimal.hpp"
#include <iostream>

AbstractAnimal::AbstractAnimal() : type("") {
    std::cout << "AbstractAnimal Default Constructor Called!" << std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &ref) : type(ref.type) {
    std::cout << "AbstractAnimal Copy Constructor Called!" << std::endl;
}

AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal &ref) {
    this->type = ref.type;
    return *this;
}

AbstractAnimal::~AbstractAnimal() { std::cout << "AbstractAnimal Destructor Called!" << std::endl; }

std::string AbstractAnimal::getType() const { return this->type; }
