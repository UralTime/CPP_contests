#include <iostream>

int f(int x, int deep)
{
    if (x < 0 || x> 2016) return deep;
    return f(x + f(x/8 - 1, deep+1);
}

int main()
{
    int ans  = 0;
    for (int i = -10000; i <= 10000; i++) {
        int kek = f(i, 0);
        if (kek > ans) ans = kek;
    }
    std::cout << ans << std::endl;
}