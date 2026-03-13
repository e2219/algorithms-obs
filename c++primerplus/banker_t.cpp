#include "banker.h"
#include <iostream>

using namespace std;

int main() {
    Account John;
    John.show();
    Account Amy("Amy", "123456", 10000);
    Amy.show();
    Amy.setcredit(5000);
    Amy.show();
    Account Fhy("Fhy", "888888", 1000000000);
    Fhy.show();
    if(Fhy.getcredit(10000000000000)) cout << "This sentence couldn't print\n";
    Fhy.getcredit(5000);
    Fhy.show();
}