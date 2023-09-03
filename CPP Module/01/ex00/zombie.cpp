#include "zombie.hpp"

Zombie::Zombie(std::string name) { this->name = name; }

Zombie::~Zombie() {
  std::cout << this->name << ": destructor called!" << std::endl;
}

void Zombie::announce() {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie(std::string name) { return new Zombie(name); }

void randomChump(std::string name) {
  Zombie zombie(name);

  zombie.announce();
}
