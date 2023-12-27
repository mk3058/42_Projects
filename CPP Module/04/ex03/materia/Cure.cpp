#include "Cure.hpp"
#include <iostream>

static const std::string materiaName = "cure";

Cure::Cure() : AMateria(materiaName) {}

Cure::Cure(const Cure &ref) : AMateria(ref.type) {}

Cure &Cure::operator=(const Cure &rval) {
    if (this == &rval) {
        return *this;
    }
    return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}