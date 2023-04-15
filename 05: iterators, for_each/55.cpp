#include <iostream>
#include <map>
#include <unordered_map>

enum { mod = 4294967161 };

int main()
{
    std::map<std::pair<unsigned long long, unsigned long long>, unsigned long long> A;
    std::unordered_map<unsigned long long, std::unordered_map<unsigned long long, unsigned long long>> B;
    std::map<std::pair<unsigned long long, unsigned long long>, unsigned long long> C;
    // we need C = A * B
    unsigned long long i, j, v;
    bool first = true;
    while (std::cin >> i >> j >> v) {
        if (i == 0 && j == 0 && v == mod) { 
            first = false; 
        } else if (first) {
            A[{i, j}] = v % mod;
        } else {
            B[i][j] = v % mod;
        }
    }
    for (auto& [pos, A_xy] : A) {
        unsigned long long x = pos.first, y = pos.second;
        if (B.find(y) != B.end()) {
            for (auto& [u, B_yu] : B[y]) {
                C[{x, u}] += A_xy % mod * B_yu % mod;
                C[{x, u}] %= mod;
            }
        }
    }
    for (auto& [pos, value] : C) {
        if (value) {
            std::cout << pos.first << " " << pos.second << " " << value << std::endl;
        }
    }
}