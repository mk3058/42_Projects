#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "AMateria.hpp"

class Inventory {
  private:
    AMateria *slots[4];
    unsigned int count;

  public:
    Inventory();
    Inventory(const Inventory &ref);
    Inventory &operator=(const Inventory &rval);
    ~Inventory();
    int add(AMateria *materia);
    AMateria *remove(unsigned int idx);
    AMateria *get(unsigned int idx) const;
};

enum { SUCCESS, FAILURE };

#endif