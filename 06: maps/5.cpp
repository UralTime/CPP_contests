#include <iostream>
#include <map>

enum { mod = 4294967161 };

int main()
{
    std::map<std::pair<unsigned long long, unsigned long long>, unsigned long long> a;
    std::map<std::pair<unsigned long long, unsigned long long>, unsigned long long> b;
    std::map<std::pair<unsigned long long, unsigned long long>, unsigned long long> mres;
    unsigned long long r, c, v, rows = 0, cols = 0;
    while (std::cin >> r >> c >> v) {
        if (!r && !c && v == mod) { 
            break; 
        } else {
            a[{r, c}] = v % mod;
        }
        if (r > rows) {
            rows = r;
        }
    }
    while (std::cin >> r >> c >> v) {
        b[{r, c}] = v % mod;
        if (c > cols) {
            cols = r;
        }
    }
    for (unsigned long long i = 0; i <= rows; ++i) {
        for (unsigned long long j = 0; j <= cols; ++j) {
            mres[{i, j}] = 0;
        }
    }
    for (const auto &x : b) {
        for (unsigned long long i = 0; i <= rows; i++) {
            mres[{i, x.first.second}] += (a[{i, x.first.first}] * x.second) % mod;
            mres[{i, x.first.second}] %= mod;
        }
    }
    for (const auto &x : mres) {
        if (x.second) {
            std::cout << x.first.first << " " << x.first.second << " " << x.second << std::endl;
        }
    }
}