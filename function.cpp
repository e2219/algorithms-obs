/*programming 8 test*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

double function1(double x, double y) {
    return 2 * x * y / (x + y);
}

void printf1() {
    double val1;
    double val2;
    cin >> val1 >> val2;
    double res;
    while(val1 != 0 && val2 != 0) {
        res = function1(val1, val2);
        cout << res << endl;
        cin >> val1 >> val2;
    }
    return ;
}

void get_scores(vector<double>& arr) {
    double value;
    int i = 0;
    cout << "Enter at most 10 scores to get the average: \n";
    while (cin >> value && i < 10) {
        arr.push_back(value);
        i += 1;
    }
}

void print_arr(vector<double>& arr) {
    for (const auto ele : arr) {
        cout << ele << endl;
    }
}

double get_average(vector<double>& arr) {
    double res = 0;
    for (const auto ele: arr) {
        res += ele;
    }
    return res / arr.size();
}

inline double add(double x, double y) {
    return x + y;
}

inline double sub(double x, double y) {
    return x - y;
}

inline double mul(double x, double y) {
    return x * y;
}

inline double div(double x, double y) {
    if(y == 0) {throw runtime_error("division by zero");}
    return x / y;
}
/*加减乘除函数*/
using Func = double (*) (double, double);

Func choose_func(const string& op) {
    if (op == "add") return add;
    if (op == "sub") return sub;
    if (op == "mul") return mul;
    if (op == "div") return div;
    return nullptr;
}


double calculate(double x, double y, Func f) {
    return f(x, y);
}

const map<string, Func> ops{
    {"add", add},
    {"sub", sub},
    {"mul", mul},
    {"div", div}
};

int main() {
    /*double (*pf[4]) (double, double) = {add, sub, mul, div};
    double val1, val2;
    while(cin >> val1 >> val2) {
        for(int i = 0; i < 4; i++) {
            cout << calculate(val1, val2, pf[i]) << "    ";
        }
        cout << endl;
    }*/
    string op;
    double val1, val2;
    cin >> val1 >> val2 >> op;
    auto it = ops.find(op);
    if(it == ops.end()) {
        cout << "Unknown option\n";
        return 0;
    }
    Func f = it->second;
    cout << calculate(val1, val2, f);
    return 0;
}
