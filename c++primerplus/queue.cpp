#include "queue.h"
#include <cstdlib>

Queue::Queue(int qs):front(nullptr), rear(nullptr), items(0), qsize(qs) {};

Queue::~Queue() {
    Node* temp;
    while (front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const {
    return items == 0;
}

bool Queue::isfull() const {
    return items == qsize;
}

int Queue::queuecount() const {
    return items;
}

bool Queue::enqueue(const Item & item) {
    if (isfull()) return false;
    Node* add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr) {
        front = add;
    }
    else rear->next = add;
    rear = add;
    return true;
}

bool Queue::dequeue(Item & item) {
    if(isempty()) return false;
    Node* temp = front;
    item = front->item;
    front = front->next;
    delete temp;
    items--;
    if(items == 0) rear = nullptr;
    return true;
}

void Customer::set(long when) {
    arrive = when;
    processtime = std::rand() % 3 + 1;
}