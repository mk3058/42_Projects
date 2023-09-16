#include "Zombie.hpp"

int main() {
  Zombie *zombie = newZombie("A");

  zombie->announce();
  randomChump("B");

  delete zombie;
}