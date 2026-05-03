#pragma once
#include <queue>
#include <utility>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
private:
    std::deque<std::pair<int, int>> body;
    Direction d;
    bool grow_flag;
public:
    void move(){};
    // 1. 根据 direction 算新头
    // 2. push_front
    // 3. if grow_flag:
    //        clear flag
    //    else:
    //        pop_backmove():
    // 1. 根据 direction 算新头
    // 2. push_front
    // 3. if grow_flag:
    //        clear flag
    //    else:
    //        pop_back
    void grow(){};
    void SetDirection(Direction d){};
    std::pair<int, int> getHead() {};

};