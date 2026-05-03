#include "card.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
    vector<Card> deck = buildDeck();
    int num = 0;
    for (auto & ele : deck) {
        num++;
    }
    cout << num << endl;
}