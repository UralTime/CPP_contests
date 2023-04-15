#include <iostream>

int main() 
{
    char c, prev = 'a';
    while ((c = getchar()) != EOF) {
        if ((c != '0') || isdigit(prev)) {
            putchar(c);
        } else {
            while (((c = getchar()) != EOF) && (c == '0')) { };
            if (!isdigit(c)) {
                putchar('0');
            }
            if (c != EOF) {
                putchar(c);
            }
        }
        prev = c;
    }
}
