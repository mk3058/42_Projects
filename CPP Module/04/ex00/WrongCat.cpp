#include "WrongCat.hpp"
#include <iostream>

static const std::string typeName = "Cat";

WrongCat::WrongCat() {
    this->type = typeName;
    std::cout << "WrongCat Default Constructor Called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref) : WrongAnimal() {
    this->type = ref.type;
    std::cout << "WrongCat Copy Constructor Called!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rval) {
    this->type = rval.type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor Called!" << std::endl;
}

void WrongCat::makeSound() const { std::cout << "mewooo~" << std::endl; }