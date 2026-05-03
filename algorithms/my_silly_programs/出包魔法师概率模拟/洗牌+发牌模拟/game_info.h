#include <vector>
#include "card.h"

using std::vector;

const int CARD_TYPE_COUNT = 8;

struct GameInfo{
    std::vector<int> knownOthers;
    std::vector<int> secretCards;
};

vector<Card> removeKnown(vector<Card> deck, const GameInfo& info);
vector<double> estimateMyHand(const GameInfo& info, int N = 100000);