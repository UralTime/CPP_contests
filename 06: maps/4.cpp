#include <iostream>
#include <map>

int main()
{
    std::map<std::pair<unsigned long long, unsigned long long>, unsigned long long> m;
    const unsigned long long mod = 4294967161;
    unsigned long long r, c, v;
    while (std::cin >> r >> c >> v) {
        if (!r && !c && v == mod) {}
        else {
            m[{r, c}] = (m[{r, c}] + v) % mod;
        }
    }
    for (auto x : m) {
        if (x.second) {
            std::cout << x.first.first << " " << x.first.second << " " << x.second << std::endl;
        }
    }
}