#ifndef CLASSINHER_H
#define CLASSINHER_H
#pragma once

#include <string>
#include <iostream>
using std::string;

class Player {
private:
    string firstname;
    string lastname;
    bool hastable;
public:
    Player() {firstname = "noname", lastname = "noname", hastable = false;};
    Player(const string & fn, const string & ln, bool ht) : firstname(fn), lastname(ln), hastable(ht) {}
};

class newPlayer : public Player {
private:
    int age;
public: 
    newPlayer(int a, const Player & pl) : age(a), Player(pl){}
    newPlayer(const string & fn, const string & ln, bool ht, int year) : Player(fn, ln, ht), age(year) {}
    
};

#endif