#include "Character.hpp"
#include "Floor.hpp"
#include <iostream>

Character::Character() : name("none") {}

Character::Character(std::string name) : name(name) {}

Character::Character(const Character &ref) : name(ref.name) {
    this->inventory = ref.inventory;
}

Character &Character::operator=(const Character &rval) {
    this->name = rval.name;
    this->inventory = rval.inventory;
    return *this;
}

Character::~Character() {}

std::string const &Character::getName() const { return name; }

void Character::equip(AMateria *m) {
    if (m == NULL) {
        std::cout << "Materia does not exist!" << std::endl;
        return;
    }
    inventory.add(m);
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 4) {
        std::cout << "Index is not valid!" << std::endl;
        return;
    }

    Floor &floor = Floor::getInstance();
    AMateria *materia = inventory.remove(idx);
    if (materia != NULL) {
        floor.add(materia);
    }
}

void Character::use(int idx, ICharacter &target) {
    AMateria *materia = inventory.get(idx);
    if (materia != NULL) {
        materia->use(target);
    }
}