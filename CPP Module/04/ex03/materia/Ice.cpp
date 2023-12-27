#include "Ice.hpp"
#include "ICharacter.hpp"
#include "iostream"

static const std::string materiaName = "ice";

Ice::Ice() : AMateria(materiaName) {}

Ice::Ice(const Ice &ref) : AMateria(ref.type) {}

Ice &Ice::operator=(const Ice &rval) {
    if (this == &rval) {
        return *this;
    }
    return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}