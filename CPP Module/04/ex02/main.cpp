#include "AbstractAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <exception>
#include <iostream>

int main() {
    const AbstractAnimal *j = new Dog();
    const AbstractAnimal *i = new Cat();

    delete j; // should not create a leak
    delete i;

    std::cout << "<=================================>\n" << std::endl;
    AbstractAnimal *AbstractAnimals[2] = {new Dog(), new Cat()};
    for (int i = 0; i < 100; i++) {
        AbstractAnimals[0]->addIdea(std::string("Dog idea"));
        AbstractAnimals[1]->addIdea(std::string("Cat idea"));
    }
    std::cout << AbstractAnimals[0]->getIdea(50) << std::endl;
    std::cout << AbstractAnimals[1]->getIdea(30) << std::endl;

    try {
        AbstractAnimals[0]->addIdea("overflowed!");
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        AbstractAnimals[0]->getIdea(-1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "<=================================>\n" << std::endl;
    AbstractAnimal *DogTmp = new Dog();
    *dynamic_cast<Dog *>(DogTmp) = *dynamic_cast<Dog *>(AbstractAnimals[0]);
    AbstractAnimal *CatTmp = new Cat();
    *dynamic_cast<Cat *>(CatTmp) = *dynamic_cast<Cat *>(AbstractAnimals[1]);
    delete AbstractAnimals[0];
    delete AbstractAnimals[1];

    std::cout << DogTmp->getIdea(50) << std::endl;
    std::cout << CatTmp->getIdea(30) << std::endl;

    delete DogTmp;
    delete CatTmp;
    return 0;
}