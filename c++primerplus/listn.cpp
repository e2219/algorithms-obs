#include "listn.h"
#include <cstddef>

Listn::Listn() {
    head = nullptr;
    count = 0;
}

Listn::~Listn() {
    Node * current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}

bool Listn::isfull() const{
    return count == MAX;
}

bool Listn::isempty() const{
    return count == 0;
}

bool Listn::add(const Item &item) {
    if(isfull()) return false;
    Node* newnode = new Node;
    newnode->item = item;
    newnode->next = nullptr;
    if (head == nullptr) head = newnode;
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newnode;
    }
    count++;
    return true;
}

void Listn::visit(void (*pf)(Item &))
{
    Node *current = head;
    while (current != nullptr)
    {
        pf(current->item);
        current = current->next;
    }
}