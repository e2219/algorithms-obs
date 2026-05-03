#pragma once
#include <string>
#include <vector>

enum CardType {
    DRAGON = 0,
    GHOST,
    DREAM,
    OWL,
    STORM,
    BLIZZARD,
    FIREBALL,
    POTION,
};

struct Card {
    CardType type;
};

std::vector<Card> buildDeck();