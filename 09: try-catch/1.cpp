#include <iostream>

class Mystring {
    std::string s;
public:
    Mystring (const std::string &str): s(str) {}
    ~Mystring () {
        std::cout << s << std::endl;
    }
};

void func() {
    std::string str;
    if (!(std::cin >> str)) {
        throw 1;
    } else {
        Mystring s{str};
        func();
    }
}

int main() {
    try {
        func();
    } catch (int) {};
}