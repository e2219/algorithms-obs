#include <iostream>
#include <thread>
#include <chrono>

class Game {
public:
    void run() {
        while (running) {
            update();
            render();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

private:
    bool running = true;

    void update() {
        // 暂时什么都不做
    }

    void render() {
        std::cout << "Game Running..." << std::endl;
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}