#pragma once
#ifndef LISTN_H

typedef int Item;

class Listn{
private:
    struct Node{
        Item item;
        Node* next; 
    };
    Node* head;
    int count;
    static const int MAX = 10;
public:
    Listn();
    ~Listn();

    bool isempty() const;
    bool isfull() const;
    bool add(const Item &item);

    void visit(void (*pf)(Item &));
};

#endif