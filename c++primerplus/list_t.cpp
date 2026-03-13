#include <iostream>
#include "lista.h"
#include "listn.h"

using namespace std;

void show(Item &item)
{
    cout << item << " ";
}

int main()
{
    Lista list1;
    Listn list2;
    for (int i = 0; i < 5; i++) {
        list1.add(i);
        list2.add(i);
    }
    list1.visit(show);
    list2.visit(show);
    cout << endl;

    return 0;
}
