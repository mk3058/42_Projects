#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {
  public:
    WrongCat();
    WrongCat(const WrongCat &ref);
    WrongCat &operator=(const WrongCat &rval);
    virtual ~WrongCat();
    void makeSound() const;
};

#endif