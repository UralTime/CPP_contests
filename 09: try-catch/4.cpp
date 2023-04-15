#include <iostream>

// Это функция Аккермана 
struct Result {
    unsigned long long res; 
    Result (unsigned long long m, unsigned long long n) 
    { 
        if (m == 0) { 
            res = n + 1; 
        } else if (n == 0) { 
            res = Result(m - 1, 1).res; 
        } else { 
            res = Result(m - 1, Result(m, n - 1).res).res; 
        } 
    } 
}; 


void func(unsigned long long a, unsigned long long b) { 
    throw Result(a, b); 
} 

int main() 
{ 
    unsigned long long a, b; 
    while (std::cin >> a >> b) { 
        try { 
            func(a, b); 
        } catch (Result R) { 
            std::cout << R.res << std::endl; 
        } 
    }
}