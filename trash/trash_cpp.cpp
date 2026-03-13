#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> vec;
    vec = {1, 2, 3};
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    return 0;
}
