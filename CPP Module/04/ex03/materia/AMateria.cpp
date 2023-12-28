#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : type("none") {}

AMateria::AMateria(const AMateria &ref) : type(ref.type) {}

AMateria &AMateria::operator=(const AMateria &rval) { 
    if (this == &rval) {
        return *this;
    }
    // do nothing. (materia type cannot be changed)
    return *this; }

AMateria::~AMateria() {}

AMateria::AMateria(std::string const &type) : type(type) {}

std::string const &AMateria::getType() const { return type; }

void AMateria::use(ICharacter &target) {
    std::cout << "Cannot call AMateria's use function to " << target.getName()
              << " Implementation needed!" << std::endl;
}