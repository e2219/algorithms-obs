#include "card.h"
#include <string>
#include <vector>

using namespace std;

vector<Card> buildDeck() {
    vector<Card> deck;
    auto add = [&](CardType t, int cnt) {
        for (int i = 0; i < cnt; i++) {
            deck.push_back({t});
        }
    };
    add(DRAGON, 1);
    add(GHOST, 2);
    add(DREAM, 3);
    add(OWL, 4);
    add(STORM, 5);
    add(BLIZZARD, 6);
    add(FIREBALL, 7);
    add(POTION, 8);
    
    return deck;
}

