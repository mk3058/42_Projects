#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
    IMateriaSource *materiaSource = new MateriaSource();
    ICharacter *me = new Character("me");
    ICharacter *bob = new Character("bob");

    std::cout
        << "<===================== MateriaSource Test =====================>\n"
        << std::endl;
    materiaSource->learnMateria(new Ice());
    materiaSource->learnMateria(new Cure());
    materiaSource->learnMateria(new Cure()); // duplicate materia
    materiaSource->learnMateria(NULL);       // null

    AMateria *tmp = materiaSource->createMateria("ice");
    me->equip(tmp);
    tmp = materiaSource->createMateria("cure");
    me->equip(tmp);
    tmp = materiaSource->createMateria("not exist"); // uninitialized materia

    std::cout
        << "<===================== Character Use Test =====================>\n"
        << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);  // unequipped materia
    me->use(-1, *bob); // invalid index
    me->use(4, *bob);  // invalid index

    std::cout << "<===================== Character equip Test "
                 "=====================>\n"
              << std::endl;
    tmp = materiaSource->createMateria("cure");
    me->equip(tmp);
    tmp = materiaSource->createMateria("cure");
    me->equip(tmp);
    tmp = materiaSource->createMateria("cure");
    me->equip(tmp); // equip more than 4 materia

    std::cout
        << "<================== Character Copy Test ===================>\n"
        << std::endl;

    Character ch("ch");
    ch.use(0, *bob); // cannot use

    ch = *dynamic_cast<Character *>(me); // copy
    delete me;                           // delete original object
    ch.use(0, *bob);

    std::cout
        << "<================== Character Copy Test ===================>\n"
        << std::endl;
    Character ch2(ch);
    ch2.use(0, *bob);

    std::cout
        << "<================== Character Unequip Test ===================>\n"
        << std::endl;
    ch2.use(0, *bob);
    ch2.unequip(0);
    ch2.use(0, *bob);

    for (int i = 0; i < 2000; i++) {
        tmp = materiaSource->createMateria("cure");
        ch2.equip(tmp);
        ch2.unequip(0);
    }

    delete bob;
    delete materiaSource;
}

// int main() {
//     IMateriaSource *src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     ICharacter *me = new Character("me");
//     ICharacter *bob = new Character("bob");
//     AMateria *tmp;

//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);

//     me->use(0, *bob);
//     me->use(1, *bob);

//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }