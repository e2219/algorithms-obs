#include "lista.h"
#include <iostream>

bool Lista::isempty() const {
    return top == 0;
}

bool Lista::isfull() const {
    return top == MAX;
}

bool Lista::add(Item & item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    }
    else return false;
}

void Lista::visit(void (*pf)(Item & item)){
    for (int i = 0; i < top; i++) {
        pf(items[i]);
    }
}