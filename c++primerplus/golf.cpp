#include "golf.h"
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;


void setgolf(golf & g, const char* name, int hc){
    strcpy(g.fullname, name);
    g.handicap = hc;
}
int setgolf(golf & g) {
    char name[Len];
    int hc;
    cout << "Enter the fullname: ";
    if(!cin.getline(name, Len)) return 0;
    if(name[0] == '\0') return 0;
    cout << "Enter the handicap: ";
    if(!(cin >> hc)) {
        cin.clear();
        cin.ignore(10000, '\n');
        return 0;
    }
    cin.get();
    setgolf(g, name, hc);
    return 1;
}
void handicap(golf & g, int hc) {
    g.handicap = hc;
}
void showgolf(const golf & g) {
    cout << "fullname: " << g.fullname << std::endl;
    cout << "handicap: " << g.handicap << std::endl;
}