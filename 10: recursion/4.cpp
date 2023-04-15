#include <iostream>
#include <string>

void rec(int m, int k) 
{
    using std::cout;
    using std::string;
    if (k <= 0) return;
    cout << string(k, 'a') << string(m - k, 'b') << string(m - k, 'c') 
        << string(k, 'd') << std::endl;
    rec(m, k - 1);
}

int main() 
{
    int n;
    std::cin >> n;
    if (n == 2 || n % 2 == 1) return 0;
    rec(n / 2, n / 2 - 1);
    return 0;
}