#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
  private:
    ScavTrap();

  public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &ref);
    ScavTrap &operator=(const ScavTrap &rval);
    ~ScavTrap();
    void attack(const std::string &target);
    void guardGate();
};

#endif