#include <iostream>
#include <string>

int check(std::string str) 
{
    if (str.find_first_not_of("01") != std::string::npos) {
        return 0;
    }
    int zeros = 0, ones = 0;
    auto it = str.begin();
    for ( ; it != str.end() && *it == '0'; it++, zeros++);
    for ( ; it != str.end() && *it == '1'; it++, ones++);
    if (zeros == 0 || ones == 0) {
        return 0;
    }
    while (it != str.end()) {
        int i = 0, j = 0;
        for ( ; it != str.end() && *it == '0' && i < zeros; i++, it++);
        for ( ; it != str.end() && *it == '1' && j < ones; j++, it++);
        if (i != zeros || j != ones) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    std::string str;
    while (std::cin >> str) {
        std::cout << check(str) << std::endl;
    } 
}