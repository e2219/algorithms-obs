#pragma once
#ifndef LISTA_H
#define LISTA_H

typedef int Item;

class Lista{
private:
    static const int MAX = 10;
    Item items[MAX];
    int top;
public: 
    Lista(){top = 0;}
    bool isempty() const;
    bool isfull() const;
    bool add(Item & item);
    void visit(void (*pf)(Item & item));
};

#endif