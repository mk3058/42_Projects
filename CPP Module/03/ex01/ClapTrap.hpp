#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
  protected:
    std::string name;
    int hitPoints; // health
    int energyPoints;
    int attackDamage;
    ClapTrap();

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