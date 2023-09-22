#include "HumanB.hpp"

#define null 0

HumanB::HumanB(std::string name) {
  this->name = name;
  this->weapon = null;
}

void HumanB::attack() {
  if ((!(this->weapon)) != null) {
    std::cout << this->name << " has nothing!" << std::endl;
    return;
  }

  std::cout << this->name << " attacks with their " << this->weapon->getType()
            << std::endl;
}

void HumanB::setWeapon(Weapon *weapon) { this->weapon = weapon; }