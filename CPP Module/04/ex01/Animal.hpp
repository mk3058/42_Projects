#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
  protected:
    std::string type;

  public:
    Animal();
    Animal(const Animal &ref);
    Animal &operator=(const Animal &ref);
    virtual ~Animal();
    std::string getType() const;
    virtual void makeSound() const;
    virtual void addIdea(std::string idea) = 0;
    virtual std::string getIdea(unsigned int index) = 0;
};

#endif