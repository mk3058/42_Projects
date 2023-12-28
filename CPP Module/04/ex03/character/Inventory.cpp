#include "Inventory.hpp"
#include <cstring>
#include <iostream>

Inventory::Inventory() : count(0) { memset(slots, 0, sizeof(slots)); }

Inventory::Inventory(const Inventory &ref) : count(ref.count) {
    for (int i = 0; i < 4; i++) {
        if (ref.slots[i] == NULL) {
            this->slots[i] = NULL;
            continue;
        }
        this->slots[i] = ref.slots[i]->clone();
    }
}

Inventory &Inventory::operator=(const Inventory &rval) {
    if (this == &rval) {
        return *this;
    }

    for (int i = 0; i < 4; i++) {
        delete this->slots[i];
        if (rval.slots[i] == NULL) {
            this->slots[i] = NULL;
            continue;
        }
        this->slots[i] = rval.slots[i]->clone();
        count++;
    }
    return *this;
}

Inventory::~Inventory() {
    for (int i = 0; i < 4; i++) {
        delete slots[i];
    }
}

int Inventory::add(AMateria *materia) {
    int emptySlotIdx = -1;

    if (materia == NULL) {
        std::cout << "Materia must be proveded!" << std::endl;
        return FAILURE;
    }
    if (count == 4) {
        std::cout << "Inventory slots are full!" << std::endl;
        return FAILURE;
    }
    for (int i = 0; i < 4; i++) {
        if (slots[i] == materia) {
            std::cout << "materia already exist in slots!" << std::endl;
            return FAILURE;
        }
        if (emptySlotIdx == -1 && slots[i] == NULL) {
            emptySlotIdx = i;
        }
    }

    slots[emptySlotIdx] = materia;
    count++;
    return SUCCESS;
}

AMateria *Inventory::remove(unsigned int idx) {
    if (idx > 3) {
        std::cout << "Inventory index out of range!" << std::endl;
        return NULL;
    }
    if (slots[idx] == NULL) {
        std::cout << idx << " slot is empty. Cannot remove!" << std::endl;
        return NULL;
    }

    AMateria *tmp = slots[idx];
    slots[idx] = NULL;
    count--;
    return (tmp);
}

AMateria *Inventory::get(unsigned int idx) const {
    if (idx > 3) {
        std::cout << "Inventory index out of range!" << std::endl;
        return NULL;
    }
    if (slots[idx] == NULL) {
        std::cout << idx << " slot is empty!" << std::endl;
        return NULL;
    }
    return slots[idx];
}