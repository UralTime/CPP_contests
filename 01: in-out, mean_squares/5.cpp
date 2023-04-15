#include <iostream>

enum
{
    OKTETS_IN_NUMBER = 4,
    NUMBERS_IN_STRING = 4,
    BITS_IN_OKTET = 8
};

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    uint32_t x;
    while (cin >> x) {
        for (uint32_t j = 0; j < NUMBERS_IN_STRING; j++) {
            uint32_t num = 0;
            for (uint32_t i = 0; i < OKTETS_IN_NUMBER; i++) {
                if (cin >> std::hex >> x) {
                    num <<= BITS_IN_OKTET;
                    num += x;
                } else {
                    return 0;
                }
            }
            cout << num << endl;
        }
    }
}
