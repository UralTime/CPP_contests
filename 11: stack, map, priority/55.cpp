#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <string>

int main()
{
    std::stack<std::string> s;
    char c;
    std::set<char> sett{'+', '-', '*', '/'};
    while (std::cin >> c) {
        if (sett.find(c) != sett.end()) {
            std::string sym1 = s.top();
            s.pop();
            std::string sym2 = s.top();
            s.pop();
            std::string cs = std::string(1, c);
            std::string str_new = "(" + sym2 + cs + sym1 + ")"; 
            s.push(str_new);
        } else {
            s.push(std::string(1, c));
        }
    }
    std::string ans = s.top();
    s.pop();
    std::cout << ans << std::endl;
}