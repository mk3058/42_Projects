#include "ClapTrap.hpp"

const int initialHitPoints = 10;
const int initialEnergyPoints = 10;
const int initialAttackDamage = 0;

ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(initialHitPoints),
      energyPoints(initialEnergyPoints), attackDamage(initialAttackDamage) {
    std::cout << "ClapTrap '" << name << "' constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rval)
    : name(rval.name), hitPoints(rval.hitPoints),
      energyPoints(rval.energyPoints), attackDamage(rval.attackDamage) {
    std::cout << "ClapTrap '" << this->name << "' copy constructor called!"
              << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rval) {

    if (this == &rval) {
        return *this;
    }
    
    this->name = rval.name;
    this->hitPoints = rval.hitPoints;
    this->energyPoints = rval.energyPoints;
    this->attackDamage = rval.attackDamage;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap '" << this->name << "' destructor called!"
              << std::endl;
}

void ClapTrap::attack(const std::string &target) {

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
    std::cout << "ClapTrap " << this->name << " attacks " << target
              << ", causing " << this->attackDamage << " points of damage!"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    int points = this->hitPoints - amount;
    this->hitPoints = points > 0 ? points : 0;

    std::cout << "ClapTrap '" << this->name << "' take " << amount
              << " of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints < 1) {
        std::cout << "Cannot be repaired! There's no energy points remaining"
                  << std::endl;
        return;
    }
    if (this->hitPoints < 1) {
        std::cout << "Cannot be repaired! There's no hit points remaining"
                  << std::endl;
        return;
    }
    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " repaired! Current hitPoint is "
              << this->hitPoints << std::endl;
}

std::string ClapTrap::getName() { return this->name; }

int ClapTrap::getAttackDamage() { return this->attackDamage; }

void ClapTrap::setAttackDamage(int attackDamage) {
    if (attackDamage < 0) {
        std::cout << "attack damage cannot be negative!" << std::endl;
        return;
    }
    this->attackDamage = attackDamage;
}

void ClapTrap::printStat() {
    std::cout << '\n'
              << "< " << this->name << "'s status >" << '\n'
              << "hitPoints: " << this->hitPoints << '\n'
              << "energyPoints: " << this->energyPoints << '\n'
              << "attackDamage: " << this->attackDamage << '\n'
              << std::endl;
}