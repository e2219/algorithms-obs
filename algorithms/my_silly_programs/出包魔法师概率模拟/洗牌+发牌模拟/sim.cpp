#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <random>
#include "card.h"
#include "game_info.h"


using namespace std;

vector<Card> dealMyHand(vector<Card>& deck) {
    vector<Card> hand;
    for (int i = 0; i < 5; i++) {
        hand.push_back(deck.back());
        deck.pop_back();
    }
    return hand;
}

void printHand(const vector<Card>& hand) {
    for (auto& c : hand) {
        cout << c.type << " ";
    }
    cout << endl;
}

int main() {
    GameInfo info;
    info.knownOthers = {2,2,3,6,7,1,4,5,6,7,0,6,7,7,7,5,5,6,6,8};
    info.secretCards = {};
    auto p = estimateMyHand(info, 100000);
    string names[] = {
    "DRAGON","GHOST","DREAM","OWL",
    "STORM","BLIZZARD","FIREBALL","POTION"
    };
    cout << fixed << setprecision(6);
    for (int i = 0; i < CARD_TYPE_COUNT; i++) {
        cout << setw(10) << left << names[i] << ": "<< setw(8) << right << p[i] << endl;
    }
}