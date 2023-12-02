#include "FragTrap.hpp"

const int initialHitPoints = 100;
const int initialEnergyPoints = 100;
const int initialAttackDamage = 30;

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = initialHitPoints;
    this->energyPoints = initialEnergyPoints;
    this->attackDamage = initialAttackDamage;
    std::cout << "FragTrap '" << name << "' constructor called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref.name) {
    ClapTrap::operator=(ref);
    std::cout << "FragTrap '" << this->name << "' copy constructor called!"
              << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rval) {
    if (&rval == this) {
        return *this;
    }

    ClapTrap::operator=(rval);
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap '" << this->name << "' destructor called!"
              << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "high Fives Guys~!" << std::endl;
}