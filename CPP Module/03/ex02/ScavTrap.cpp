#include "ScavTrap.hpp"

const int initialHitPoints = 100;
const int initialEnergyPoints = 50;
const int initialAttackDamage = 20;

ScavTrap::ScavTrap() {
    hitPoints = initialHitPoints;
    energyPoints = initialEnergyPoints;
    attackDamage = initialAttackDamage;
    std::cout << "ScavTrap default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

    hitPoints = initialHitPoints;
    energyPoints = initialEnergyPoints;
    attackDamage = initialAttackDamage;
    std::cout << "ScavTrap '" << name << "' constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref) {
    std::cout << "ScavTrap '" << this->name << "' copy constructor called!"
              << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rval) {
    if (this == &rval) {
        return *this;
    }

    ClapTrap::operator=(rval);
    return *this;
}

void ScavTrap::attack(const std::string &target) {

    if (this->energyPoints < 1) {
        std::cout << "Cannot Attack! There's no energy points remaining"
                  << std::endl;
        return;
    }
    if (this->hitPoints < 1) {
        std::cout << "Cannot Attack! There's no hit points remaining"
                  << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ScavTrap " << this->name << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!"
              << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap '" << this->name << "' destructor called!"
              << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrp " << this->name << "is in keeper mode" << std::endl;
}