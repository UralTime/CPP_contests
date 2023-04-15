#include <iostream>
#include <vector>
#include <bit>
#include <algorithm>

int main()
{
    using std::popcount;
    std::vector<unsigned> v;
    unsigned kek;
    while (std::cin >> kek) {
        v.push_back(kek);
    }
    std::stable_sort(v.begin(), v.end(), [] (auto a, auto b) {return popcount(a) < popcount(b);});
    for (auto x:v) {
        std::cout << x << std::endl;
    }
}