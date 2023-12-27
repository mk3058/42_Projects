#include "Floor.hpp"
#include <cstring>

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
    size = size + 1 > 1000 ? 1000 : size + 1;
    if (index + 1 > 1000) {
        index %= 1000;
        delete materias[index];
    }

    materias[index++] = materia;
}

Floor::~Floor() {
    for (int i = 0; i < 1000; i++) {
        delete materias[i];
    }
}