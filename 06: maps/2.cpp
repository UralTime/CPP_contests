#include <iostream>
#include <map>
#include <string>

int main()
{   
    std::map<std::string,std::pair<double, int>> m;
    std::string s;
    double kek;
    while (std::cin >> s >> kek) {
        m[s].first += kek;
        m[s].second++;
    }
    for (auto x:m) {
        std::cout << x.first << " " << x.second.first / x.second.second << std::endl;
    }
}