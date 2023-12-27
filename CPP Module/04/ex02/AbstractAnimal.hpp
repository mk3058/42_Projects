#ifndef ABSTRACTANIMAL_HPP
#define ABSTRACTANIMAL_HPP

#include <string>

class AbstractAnimal {
  protected:
    std::string type;

  public:
    AbstractAnimal();
    AbstractAnimal(const AbstractAnimal &ref);
    AbstractAnimal &operator=(const AbstractAnimal &ref);
    virtual ~AbstractAnimal();
    std::string getType() const;
    virtual void makeSound() const = 0;
    virtual void addIdea(std::string idea) = 0;
    virtual std::string getIdea(unsigned int index) = 0;
};

#endif