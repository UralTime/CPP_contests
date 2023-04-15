#include <iostream>
#include <cctype>

int main() 
{
    using std::cout;
    using std::endl;
    using std::cin;
    bool ans = true;
    bool flag = false;
    bool first = true;
    char c = '0';
    while (cin >> std::noskipws >> c) {
        if (isspace(c)) {
            if (first) {
                if (ans) cout << "1" << endl;
                else cout << "0" << endl;
                ans = true;
                flag = false;
                first = false;
            }
            continue;
        } else first = true;
        if ((c != '3') && (c != '4')) {
            flag = true;
        }
        if (flag) {
            if ((c != '1') && (c != '2')) {
                ans = false;
            }
            else {
                flag = true;
            }
        }
    }
}