#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "AMateria.hpp"

class Floor {
  private:
    AMateria *materias[1000];
    int size;
    int index;
    Floor();
    Floor(const Floor &ref);
    Floor &operator=(const Floor &ref);

  public:
    static Floor &getInstance();
    void add(AMateria *materia);
    ~Floor();
};

#endif