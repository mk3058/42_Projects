#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
  public:
    Ice();
    Ice(const Ice &ref);
    Ice &operator=(const Ice &rval);
    virtual ~Ice();
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif