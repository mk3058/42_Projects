#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Inventory.hpp"

class Character : public ICharacter {
  private:
    Inventory inventory;
    std::string name;
    Character();
    Character(const Character &ref);
    Character &operator=(const Character &rval);

  public:
    Character(std::string name);
    virtual ~Character();
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif