#include <iostream>
#include "stack.h"
#include <cctype>

using namespace std;

int main() {
    char ch;
    long total = 0;
    customer cu;
    Stack sk;
    cout << "Please enter A to add a customer order,\n";
    cout << "p to process a customer, or Q to quit\n";
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n') continue;
        if(!isalpha(ch)) {
            cout << "Invaild enter! Try it again.\n";
            continue;
        }
        switch(ch) {
            case 'A':
            case 'a': cout << "Enter a customer to add: ";
                      cin >> cu.fullname;
                      cout << "And his payment: ";
                      cin >> cu.payment;
                      if(sk.isfull()) {
                        cout << "Stack is full!\n";
                        break;
                      } 
                      else sk.push(cu);
                      break;
            case 'P':
            case 'p': if(sk.isempty()) {
                        cout << "Stack is already empty!\n";
                        break;
                      }
                      else sk.pop(cu);
                      cout << "cu #" << cu.fullname << " " << cu.payment << endl;
                      total += cu.payment;
                      break;
            }
        cout << "Please enter A to add a customer order,\n";
        cout << "p to process a customer, or Q to quit\n";
    }
    cout << "total: " << total << endl;
    cout << "Bye!\n";
    return 0;
}