#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
  public:
    Cure();
    Cure(const Cure &ref);
    Cure &operator=(const Cure &rval);
    virtual ~Cure();
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif