#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  private:
    AMateria *source[4];
    unsigned int index;
    MateriaSource(const MateriaSource &ref);
    MateriaSource &operator=(const MateriaSource &rval);

  public:
    MateriaSource();
    virtual ~MateriaSource();
    void learnMateria(AMateria *materia);
    AMateria *createMateria(std::string const &type);
};

#endif