#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

class Sum
{
public:
    double sum{0};
    int count{0};
    void operator() (double n) {
        sum += n;
        count++;
    }
};

int main() 
{
    std::vector<double> v;
    double kek;
    while (std::cin >> kek) {
        v.push_back(kek);
    }
    int trashhold = (int) (v.size() * 0.1);
    std::sort(v.begin() + trashhold, v.end() - trashhold);
    int extrem = (int) ((v.size() - 2 * trashhold) * 0.1);
    Sum sumo = std::for_each(v.begin() + trashhold + extrem, v.end() - trashhold - extrem, Sum());
    std::cout << std::setprecision(10) << (double) sumo.sum / sumo.count << std::endl;
}