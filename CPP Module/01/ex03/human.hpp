#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>
#include <string>

#include "weapon.hpp"

class HumanA {
 private:
  std::string name;
  Weapon &weapon;

 public:
  HumanA(std::string name, Weapon &weapon);
  void attack();
};

class HumanB {
 private:
  std::string name;
  Weapon *weapon;

 public:
  HumanB(std::string name);
  void setWeapon(Weapon *weapon);
  void attack();
};

#endif