#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

const int initialHitPoints = 10;
const int initialEnergyPoints = 10;
const int initialAttackDamage = 0;

class ClapTrap {
  private:
    std::string name;
    int hitPoints; // health
    int energyPoints;
    int attackDamage;

  public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &rval);
    ClapTrap &operator=(const ClapTrap &rval);
    ~ClapTrap();
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    std::string getName();
    int getAttackDamage();
    void setAttackDamage(int attackDamage);
    void printStat();
};

#endif