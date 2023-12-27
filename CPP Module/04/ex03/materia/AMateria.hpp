#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
  private:
    AMateria();

  protected:
    std::string type;

  public:
    AMateria(const AMateria &ref);
    AMateria &operator=(const AMateria &rval);
    virtual ~AMateria();
    AMateria(std::string const &type);
    std::string const &getType() const; // Returns the materia type
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif