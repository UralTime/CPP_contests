#include <iostream>

using std::cin;
using std::cout;

class A {
    int x;
    bool flag = false;
public:
    A () {
        cin >> x;
    }
    A (const A& a): flag{true} {
        cin >> x;
        x += a.x;
    }
    ~A () {
        if (flag) {
            cout << x << "\n";
        }
    }
};
