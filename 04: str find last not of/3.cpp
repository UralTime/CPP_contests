#include <algorithm>
#include <iostream>

int main()
{
    int n, m;
    std::cin >> m >> n;
    int r1, c1, r2, c2;
    while (std::cin >> r1 >> c1 >> r2 >> c2) {
        if (r1 > r2) std::swap(r1, r2);
        if (c1 > c2) std::swap(c1, c2);
        std::cout << std::min(r1 + m - r2, r2 - r1) + std::min(c1 + n - c2, c2 - c1) << std::endl;
    } 
}