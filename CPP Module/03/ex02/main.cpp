#include "FragTrap.hpp"

int main() {
    FragTrap A("A"), B("B");

    // 기본 기능 테스트
    //  initialize
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

    // 캐노니컬 폼
    FragTrap C("C");
    C.printStat();

    C.setAttackDamage(100000);
    FragTrap D(C);
    D.printStat();

    FragTrap E("E");
    E = C;
    E.printStat();
}