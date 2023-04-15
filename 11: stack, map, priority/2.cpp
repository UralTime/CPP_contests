#include <iostream>
#include <map>
#include <string>
#include <set>

int main() 
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    string str_cur, str_next;
    char c;
    cin >> str_cur;
    std::map<string, std::map<char, string>> dka;
    while (str_cur != "END") {
        cin >> c;
        cin >> str_next;
        dka[str_cur][c] = str_next;
        cin >> str_cur;
    }
    std::set<string> finals;
    cin >> str_cur;
    while (str_cur != "END") {
        finals.insert(str_cur);
        cin >> str_cur;
    }
    int read_syms = 0;
    cin >> str_cur;
    while (cin >> c) {
        if ((dka.find(str_cur) != dka.end()) && (dka[str_cur].find(c) != dka[str_cur].end())) {
            str_cur = dka[str_cur][c];
            read_syms++;
        } else {
            cout << 0 << endl << read_syms << endl << str_cur << endl;
            return 0;
        }
    }
    if (finals.find(str_cur) != finals.end()) {
        cout << 1 << endl; 
    } else {
        cout << 0 << endl;
    }
    cout << read_syms << endl << str_cur << endl;
}