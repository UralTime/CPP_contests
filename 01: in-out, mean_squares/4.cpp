#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    double x, mean{0}, mean_squares{0};  
    int n{0};
    while (cin >> x) {
        mean += x;
        mean_squares += x * x;
        n++;
    }
    mean /= n;
    mean_squares /= n;
    double sigma = sqrt(mean_squares - mean * mean);
    cout << std::fixed;
    cout << std::setprecision(10) << mean << endl;
    cout << std::setprecision(10) << sigma << endl; 
}
