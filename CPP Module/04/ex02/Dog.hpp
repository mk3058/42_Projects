#ifndef DOG_HPP
#define DOG_HPP

#include "AbstractAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public AbstractAnimal {
  private:
    Brain *brain;

  public:
    Dog();
    Dog(const Dog &ref);
    Dog &operator=(const Dog &rval);
    virtual ~Dog();
    void makeSound() const;
    void addIdea(std::string idea);
    std::string getIdea(unsigned int index);
};

#endif