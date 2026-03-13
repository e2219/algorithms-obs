#include "golf.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Enter the test cases you want:";
    int n;
    cin >> n;
    cin.get();
    golf *emp = new golf[n];
    int i = 0;
    while(i < n && setgolf(emp[i])) {
        showgolf(emp[i]);
        cout << endl;
        i++;
    }
    cout << "Done!";
}