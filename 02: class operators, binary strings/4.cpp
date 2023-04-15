#include <iostream>

void write(char prev, int *count)
{
    using std::cout;
    if (*count <= 4 && prev != '#') {
        for (int _ = 0; _ < *count; _++) {
            cout << prev;
        }
    } else {
        cout << '#' << prev << std::hex << *count << '#';
    }
    *count = 1;
}

int main() 
{
    using std::cin;
    char c, prev = '\t';
    int count = 0;
    while (cin >> std::noskipws >> c) {
        if (c != prev) {
            write(prev, &count);
        } else {
            count++;
        }
        prev = c;
    }
    write(prev, &count);
}