#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
  public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &ref);
    ScavTrap &operator=(const ScavTrap &rval);
    ~ScavTrap();
    void guardGate();
};

#endif