#include "zombie.hpp"

int main() {
  int num = 10;
  Zombie *zombies = zombieHorde(num, "Zombie");

  for (int i = 0; i < num; i++) {
    zombies[i].announce();
  }
  delete[] zombies;
}