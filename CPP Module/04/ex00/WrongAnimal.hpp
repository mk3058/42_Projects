#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
  protected:
    std::string type;

  public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &ref);
    WrongAnimal &operator=(const WrongAnimal &ref);
    virtual ~WrongAnimal();
    std::string getType() const;
    void makeSound() const;
};

#endif