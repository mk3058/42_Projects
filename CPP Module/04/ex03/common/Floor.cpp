#include "Floor.hpp"
#include <cstring>
#include <iostream>

Floor::Floor() : size(0), index(0) { memset(materias, 0, sizeof(materias)); }

Floor::Floor(const Floor &ref) : size(ref.size), index(ref.index) {
    for (int i = 0; i < size; i++) {
        materias[i] = ref.materias[i];
    }
}

Floor &Floor::operator=(const Floor &ref) {
    if (this == &ref) {
        return *this;
    }

    this->size = ref.size;
    this->index = ref.index;
    for (int i = 0; i < size; i++) {
        materias[i] = ref.materias[i];
    }
    return *this;
}

Floor &Floor::getInstance() {
    static Floor instance;

    return instance;
}

void Floor::add(AMateria *materia) {
    if (materia == NULL) {
        std::cout << "materia must be provided!" << std::endl;
        return;
    }

    if (index + 1 > 1000) {
        index %= 1000;
    }
    if (size >= 1000) {
        delete materias[index];
    } else {
        size++;
    }
    materias[index++] = materia;
}

Floor::~Floor() {
    for (int i = 0; i < size; i++) {
        delete materias[i];
    }
}