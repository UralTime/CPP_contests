#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

int main(int argc, char *argv[])
{
    using namespace numbers;
    complex c(argv[1]);
    double r;
    int n;
    std::stringstream(argv[2]) >> r;
    std::stringstream(argv[3]) >> n;
    std::vector<std::string> func;
    for (int i = 4; i < argc; ++i) {
        func.push_back(argv[i]);
    }
    const double pi = 4 * atan(1);
    double delta_phi = 2 * pi / n,  angle = 0;
    complex integral;
    for (int i = 0; i < n; i++, angle += delta_phi) {
        complex z0(r * cos(angle) + c.re(), r * sin(angle) + c.im());
        complex z1(r * cos(angle + delta_phi) + c.re(), r * sin(angle + delta_phi) + c.im());
        complex z(r * cos(angle + delta_phi / 2) + c.re(), r * sin(angle + delta_phi / 2) + c.im());
        integral += eval(func, z) * (z1 - z0);
    }
    std::cout << integral.to_string() << std::endl;
}