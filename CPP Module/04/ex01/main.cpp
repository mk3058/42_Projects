#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <exception>
#include <iostream>

int main() {
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    delete j; // should not create a leak
    delete i;

    std::cout << "<=================================>\n" << std::endl;
    Animal *animals[2] = {new Dog(), new Cat()};
    for (int i = 0; i < 100; i++) {
        animals[0]->addIdea(std::string("Dog idea"));
        animals[1]->addIdea(std::string("Cat idea"));
    }
    std::cout << animals[0]->getIdea(50) << std::endl;
    std::cout << animals[1]->getIdea(30) << std::endl;

    try {
        animals[0]->addIdea("overflowed!");
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        animals[0]->getIdea(-1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "<=================================>\n" << std::endl;
    Animal *DogTmp = new Dog();
    *dynamic_cast<Dog *>(DogTmp) = *dynamic_cast<Dog *>(animals[0]);
    Animal *CatTmp = new Cat();
    *dynamic_cast<Cat *>(CatTmp) = *dynamic_cast<Cat *>(animals[1]);
    delete animals[0];
    delete animals[1];

    std::cout << DogTmp->getIdea(50) << std::endl;
    std::cout << CatTmp->getIdea(30) << std::endl;

    delete DogTmp;
    delete CatTmp;
    return 0;
}