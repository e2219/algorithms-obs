#include "card.h"
#include "game_info.h"
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

vector<Card> dealMyHand(vector<Card>& deck);

vector<Card> removeKnown(vector<Card> deck, const GameInfo& info) {
    auto removeOne = [&](int t) { //匿名函数[&]引用捕获外部变量，允许 lambda 使用 t
        auto it = find_if(deck.begin(), deck.end(),
                          [&](const Card& c) {
                              return (int)c.type == t; //在牌堆中查找 t 牌
                          }); //it 是一个迭代器，指向容器元素的位置指针
        if (it != deck.end()) deck.erase(it); //如果找到，就删除
    };
    for (auto t : info.knownOthers) removeOne(t);
    for (auto t : info.secretCards) removeOne(t);
    return deck;
}

vector<double> estimateMyHand(const GameInfo& info, int N) {
    vector<long long> freq(CARD_TYPE_COUNT, 0);
    mt19937 rng(random_device{}());

    for (int i = 0; i < N; i++) {
        vector<Card> deck = buildDeck();
        deck = removeKnown(deck, info);
        shuffle(deck.begin(), deck.end(), rng);
        vector<Card> myHand = dealMyHand(deck);
        for (auto &c : myHand) {
            freq[c.type]++;
        }
    }
    vector<double> prob(CARD_TYPE_COUNT);

    for (int t = 0; t < CARD_TYPE_COUNT; t++) {
        prob[t] = (double)freq[t] / (N * 5);
    }

    return prob;
}

