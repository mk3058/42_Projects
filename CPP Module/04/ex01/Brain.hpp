#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <exception>
#include <iostream>
#include <string>

class Brain {
  private:
    std::string ideas[100];
    unsigned int index;

  public:
    Brain();
    Brain(const Brain &ref);
    Brain &operator=(const Brain &rval);
    ~Brain();
    void add(std::string idea);
    std::string get(unsigned int index);
};

#endif