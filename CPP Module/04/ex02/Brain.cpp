#include "Brain.hpp"

static const int maximumIndexSize = 100;

Brain::Brain() : index(0) {
    std::cout << "Brain Default Constructor Called!" << std::endl;
}

Brain::Brain(const Brain &ref) : index(ref.index) {
    std::cout << "Brain Copy Constructor Called!" << std::endl;
    for (unsigned int i = 0; i < index; i++) {
        this->ideas[i] = ref.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &rval) {
    this->index = rval.index;
    for (unsigned int i = 0; i < index; i++) {
        this->ideas[i] = rval.ideas[i];
    }

    return *this;
}

Brain::~Brain() { std::cout << "Brain Destructor Called!" << std::endl; }

void Brain::add(std::string idea) {
    if (this->index >= maximumIndexSize) {
        throw std::out_of_range("Cannot add new idea. Brain is full!");
    }
    ideas[this->index++] = idea;
}

std::string Brain::get(unsigned int index) {
    if (index > this->index) {
        throw std::out_of_range("index is invalid!");
    }
    return ideas[--index];
}