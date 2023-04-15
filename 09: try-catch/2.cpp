#include <iostream>

struct S
{
    int num = 0;
    bool flag = true, eof = false;

    void myfunc() {
        int x = 0;
        std::cin >> x;
        eof = std::cin.eof();
        if (flag) {
            flag = eof;
        }
        num += x;
    }
    S() {
        myfunc();
    }
    S(S&& other): num(other.num), flag(other.flag) {
        myfunc();
    }

    ~S() {
        if (eof && !flag) {
            std::cout << num << std::endl;
        }
    }

    operator bool() const {
        return !eof;
    }
};