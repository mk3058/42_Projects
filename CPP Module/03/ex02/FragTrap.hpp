#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
  public:
    FragTrap(std::string name);
    FragTrap(const FragTrap &ref);
    FragTrap &operator=(const FragTrap &rval);
    ~FragTrap();
    void highFivesGuys();
};

#endif