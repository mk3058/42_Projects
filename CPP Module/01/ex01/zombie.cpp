#include "zombie.hpp"

Zombie::Zombie() {
  std::cout << "Default Constructor Called!" << std::endl;
  this->name = "UNSET";
}

Zombie::Zombie(std::string name) {
  std::cout << "Constructor Called with 'name' parameter" << std::endl;
  this->name = name;
}

Zombie::~Zombie() {
  std::cout << this->name << ": destructor called!" << std::endl;
}

void Zombie::announce() {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
  std::cout << "name setter called!" << std::endl;
  this->name = name;
}

Zombie *newZombie(std::string name) { return new Zombie(name); }

void randomChump(std::string name) {
  Zombie zombie(name);

  zombie.announce();
}
