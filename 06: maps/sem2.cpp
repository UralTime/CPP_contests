#include <iostream>
#include <map>
#include <string>
using namespace std;

template<typename C = float, int N = 10>
C func(const C &a)
{
    return a + N;
}

int main()
{
    const int kek = 20;
    const int &lol = kek;
    auto r1 = func<int, lol>(100);
    cout << r1 << endl;
    auto r2 = func<int>(200);
    cout << r2 << endl;
    auto r3 = func(300);
    cout << r3 << endl;
}