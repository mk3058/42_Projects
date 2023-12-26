#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal {
  private:
    Brain *brain;

  public:
    Cat();
    Cat(const Cat &ref);
    Cat &operator=(const Cat &rval);
    virtual ~Cat();
    void makeSound() const;
    void addIdea(std::string idea);
    std::string getIdea(unsigned int index);
};

#endif