#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal {
  public:
    Dog();
    Dog(const Dog &ref);
    Dog &operator=(const Dog &rval);
    virtual ~Dog();
    void makeSound() const;
};

#endif