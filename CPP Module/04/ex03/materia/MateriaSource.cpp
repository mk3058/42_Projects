#include "MateriaSource.hpp"
#include <cstring>
#include <iostream>

MateriaSource::MateriaSource() : index(0) { memset(source, 0, sizeof(source)); }

MateriaSource::MateriaSource(const MateriaSource &ref) : index(ref.index) {
    for (int i = 0; i < 4; i++) {
        if (ref.source[i] == NULL) {
            this->source[i] = NULL;
            continue;
        }
        this->source[i] = ref.source[i]->clone();
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rval) {
    if (this == &rval) {
        return *this;
    }
    for (int i = 0; i < 4; i++) {
        delete this->source[i];
        if (rval.source[i] == NULL) {
            this->source[i] = NULL;
            continue;
        }
        this->source[i] = rval.source[i]->clone();
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        delete source[i];
    }
}

void MateriaSource::learnMateria(AMateria *materia) {
    if (materia == NULL) {
        std::cout << "Materia must be provided!" << std::endl;
        return;
    }
    if (index >= 4) {
        std::cout << "Materia Source is full!" << std::endl;
        delete materia;
        return;
    }
    for (unsigned int i = 0; i < index; i++) {
        if (source[i]->getType() == materia->getType()) {
            std::cout << "Same materia already exists in source!" << std::endl;
            delete materia;
            return;
        }
    }
    source[index++] = materia;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (unsigned int i = 0; i < index; i++) {
        if (source[i]->getType() == type) {
            return source[i]->clone();
        }
    }
    std::cout << "Cannot find materia named '" << type << "'" << std::endl;
    return NULL;
}