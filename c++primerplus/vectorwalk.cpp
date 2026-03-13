#include <iostream>
#include <fstream>
#include <random>
#include "vector.h"
#include <climits>

using namespace std;

random_device rd;              // 真随机（或伪）
mt19937 gen(rd());             // 随机数引擎（梅森旋转）
std::uniform_real_distribution<double> dis(0.0, 360.0);;

int main() {
    using VECTOR::Vector;
    double direction;
    int test_cases;
    int i = 0;
    int max_step = 0;
    int min_step = INT_MAX;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    ofstream file;
    file.open("random_walk.txt");
    cout << "Enter the test_cases you want to try: ";
    cin >> test_cases;
    cout << "Enter target distance(q to quit): ";
    while (cin >> target && i < test_cases) {
        cout << "Enter step length: ";
        if (!(cin >> dstep)) break;
        file << "Your target distance: " << target << endl;
        file << "Your step length: " << dstep << endl;
        while (result.magval() < target) {
            direction = dis(gen);
            step.reset(dstep, direction, Vector::POL);
            result = step + result;
            steps++;
            file << "steps: " << steps << "    " << result << endl;
        }
        file << "After " << steps << " steps, the subject has the following location:\n";
        file << result << endl;
        result.polar_mode();
        file << result << endl;
        if (steps > max_step) max_step = steps;
        if (steps < min_step) min_step = steps;
        file << "Average outward distance per step = " << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        i++;
        file << endl;
        file << endl;
        cout << "Enter target distance(q to quit): ";
    }
    file << "max steps: " << max_step << endl;
    file << "min steps: " << min_step << endl;
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n') continue;
    return 0;
}