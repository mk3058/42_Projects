#include "Zombie.hpp"

Zombie::Zombie(std::string name) { 
  std::cout << name << ": name constructor called!" << std::endl;
  this->name = name; 
}

Zombie::~Zombie() {
  std::cout << this->name << ": destructor called!" << std::endl;
}

void Zombie::announce() {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}