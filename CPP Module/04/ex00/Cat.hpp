#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal {
  public:
    Cat();
    Cat(const Cat &ref);
    Cat &operator=(const Cat &rval);
    virtual ~Cat();
    void makeSound() const;
};

#endif