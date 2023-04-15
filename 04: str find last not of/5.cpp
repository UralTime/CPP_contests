#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

int main()
{
    std::string str;
    std::getline(std::cin, str);
    str.erase(str.find_last_not_of(" \n\t\r") + 1);
    int len = str.length();
    char *buf = new char[len + 1];
    strcpy(buf, str.c_str());
    using std::pair;
    std::vector <pair <char*, int> > v;
    for (int i = 0; i < len; ++i) {
        pair <char*, int> p = {buf + i, i};
        v.push_back(p);
    }
    std::sort(v.begin(), v.end(), [] (auto a, auto b) { return (strcmp(a.first, b.first) < 0); });
    for (auto x : v) {
        std::cout << x.second << std::endl;
    }
}