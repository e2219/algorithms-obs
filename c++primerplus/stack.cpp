#include "stack.h"

Stack::Stack() {
    top = 0;
}

bool Stack::isempty() const {
    return top == 0;
}

bool Stack::isfull() const {
    return top == MAX;
}

bool Stack::push(const Item& item) {
    if (top < MAX) {
        items[top++] = item;
        return 1;
    }
    else return 0;
}

bool Stack::pop(Item& item) {
    if (top > 0) {
        item = items[--top];
        return 1;
    }
    else return 0;
}

