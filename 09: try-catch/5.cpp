#include <iostream>
#include <boost/date_time.hpp>

int main()
{
    std::string s;
    std::cin >> s;
    char c;
    int year, month, day;
    std::istringstream(s) >> year >> c >> month >> c >> day;
    boost::gregorian::date prev(year, month, day);
    int res = 0;
    while (std::cin >> s) {
        std::istringstream(s) >> year >> c >> month >> c >> day;
        boost::gregorian::date cur(year, month, day);
        res += abs((cur - prev).days());
        prev = cur;
    }
    std::cout << res << std::endl;
}