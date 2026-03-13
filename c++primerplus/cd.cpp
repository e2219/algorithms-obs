#include <iostream>
#include <cstring>
#include <cstdlib>
#include "cd.h"

using std::cout;
using std::endl;

Cd::Cd() {
    performers = new char[80];
    strcpy(performers, "unknown");
    label = new char[80];
    strcpy(label, "unknown");
    selections = 0;
    playtime = 0.0;
}

Cd::Cd(const Cd & d) {
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd(const char* s1, const char* s2, int n, double playtimes) {
    performers = new char[strlen(s1) + 1];
    label = new char[strlen(s2) + 1];
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = playtimes;
}

Cd::~Cd() {
    delete [] performers;
    delete [] label;
}

void Cd::Report() const{
    cout << "Performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "selections: " << selections;
    cout << "   playtime:" << playtime << endl;
}

Cd & Cd::operator=(const Cd & d) {
    if (this == &d)
        return *this; 
    delete[] performers;
    delete[] label;
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic(const Classic & d) : Cd(d), work(nullptr){
    work = new char[strlen(d.work) + 1];
    strcpy(work, d.work);
}

Classic::Classic(const char* s1, const char* s2, int n, double playtimes, const char* w) : Cd(s1, s2, n, playtimes), work(nullptr) {
    work = new char[strlen(w) + 1];
    strcpy(work, w);
}

Classic::~Classic() {
    delete [] work;
}

void Classic::Report() const {
    cout <<"\n";
    Cd::Report();
    cout << "work: " << work;
    cout << endl;
    cout << endl;
}

Classic & Classic::operator=(const Classic & d) {
    if (this == &d)
        return *this;   
    Cd::operator=(d);
    delete [] work;
    work = new char[strlen(d.work) + 1];
    strcpy(work, d.work);
    return *this; 
}
