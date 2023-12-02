#include "ScavTrap.hpp"

int main() {
    ScavTrap A("A"), B("B");

    // initialize
    A.setAttackDamage(3);
    A.printStat();
    B.printStat();

    // Attack
    for (int i = 0; i < 3; i++) {
        A.attack(B.getName());
        B.takeDamage(A.getAttackDamage());
    }
    A.printStat();
    B.printStat();

    // Repair
    B.beRepaired(4);
    A.printStat();
    B.printStat();

    for (int i = 0; i < 10; i++) {
        A.attack(B.getName());
        B.takeDamage(A.getAttackDamage());
    }
    B.beRepaired(10);
    A.printStat();
    B.printStat();

    ScavTrap newScav("asdfasdf");
    A = newScav;
    A.printStat();
}