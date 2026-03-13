#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cstddef>   

using namespace std;

string head(string s, int n = 1) {
    string res;
    if (n > s.size()) return "None";
    else{
        for (int i = 0; i < n; i++) {
            res += s[i];
        }
    }
    return res;
}

unsigned long head(unsigned long num, unsigned ct) {
    unsigned digits = 1;
    unsigned long n = num;
    if (ct == 0 || num == 0) return 0;
    while (n /= 10) {
        digits++;
    }
    if (digits > ct) {
        ct = digits - ct;
        while (ct--) 
            num /= 10;
    }
    return num;
}

/*非模板 > 具体化 > 常规模版*/
// 常规模板
template <typename T>
void Swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T, typename U>
auto ft(T x, U y) -> decltype(x + y) {
    return x + y;
}
// 显式模板具体化
// template<> 返回类型 函数名<具体类型>(参数列表)  必须依赖主模板存在
struct job{
    char name[40];
    double salary;
    int floor;
};
// 同用一个 T 模板，但当 T 为 job 时，使用具体化。
template<> void Swap<job>(job &a, job &b) {
    double tmp1;
    int tmp2;
    tmp1 = a.salary;
    a.salary = b.salary;
    b.salary = tmp1;
    tmp2 = a.floor;
    a.floor = b.floor;
    b.floor = tmp2;
}
//但是不如重载, 没什么屌用
//对比显式实例化 template 返回类型 函数名<具体类型>(参数列表) 显示实例化可减少编译时间

struct blot {int a; char b[10];};


void test_for_template() {
    double a = 100;
    double b = 3.14;
    cout << a << " and " << b << endl;
    Swap(a, b);
    cout << a << " and " << b << endl;
    job Joh = {"John", 3600.5, 7};
    job Jan = {"Janet", 8000, 9};
    cout << Joh.salary << "    " << Joh.floor << endl;
    cout << Jan.salary << "    " << Jan.floor << endl;
    Swap(Joh, Jan);
    cout << Joh.salary << "    " << Joh.floor << endl;
    cout << Jan.salary << "    " << Jan.floor << endl;
    Swap(Joh.salary, Jan.salary);
    cout << Joh.salary << endl;
    cout << Jan.salary << endl;
}

void silly_func(const char* s, int n = 0) {
    cout << s << endl;
}

struct CandyBar {
    char* name;
    double weight;
    int calorie;
};

void set_cb(CandyBar & emp, const char* s = "Millenniurm Munch", const double wei = 2.85, const int cal = 350) {
    strcpy(emp.name, s);
    emp.weight = wei;
    emp.calorie = cal;
}

void show_cb(const CandyBar & emp) {
    cout << "CandyBar's name: " << emp.name << endl;
    cout << "CandyBar's weight: " << emp.weight << endl;
    cout << "CandyBar's calorie: " << emp.calorie << endl;
}

string upper(string & s) {
    for (auto &ch : s) {
        ch = toupper(ch);
    }
    return s;
}

void get_upper() {
    cout << "Enter a string (q to quit): ";
    string s;
    while (getline(cin, s)) {
        if (s == "q") break;
        cout << upper(s) << endl;
        cout << "Next string(q to quit): ";
    }
    cout << "Bye.";
}

template <typename T>
T max5(const T arr[5]) {
    T mx = arr[0];
    for (int i = 1; i < 5; i++) {
        mx = max(mx, arr[i]);
    }
    return mx;
}

template <typename T>
T maxn(const T arr[], int n) {
    T mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

template<>
const char* maxn(const char* const s[], int n) {
    const char* mx = s[0];
    size_t maxlen = strlen(s[0]);
    for (int i = 1; i < n; i++) {
        size_t len = strlen(s[i]);
        if (len > maxlen) {
            maxlen = len;
            mx = s[i];
        }
    }
    return mx;
}

namespace{
    int counts;
}

int main() {
    counts = 10;
    cout << counts;
}