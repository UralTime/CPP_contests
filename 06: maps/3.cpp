#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <set>
#include <map>

class Date
{
    int year, month, day;

public:
    Date() {};
    Date(std::string str) {
        sscanf(str.c_str(), "%d/%d/%d", &year, &month, &day);
    }

    friend bool operator < (const Date &d1, const Date &d2);

    int getDay()  const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }        

    ~Date() {};
};

std::ostream& operator << (std::ostream &out, const Date &d) {
    return out << d.getYear() << "/" << std::setw(2) << std::setfill('0') 
        << d.getMonth() << "/" << std::setw(2) << std::setfill('0') << d.getDay();
}

bool operator < (const Date &d1, const Date &d2) {
    if (d1.year < d2.year) {
        return true;
    }
    if (d1.year == d2.year) {
        if (d1.month < d2.month) {
            return true;
        }
        if (d1.month == d2.month) {
            return d1.day < d2.day;
        }
    }
    return false;
};

int main()
{
    using std::cout;
    using std::cin;
    std::map<std::string, std::map<Date, int>> m;
    std::string name, date;
    int mark;
    std::set<Date> dates;
    while (cin >> name >> date >> mark) {
        m[name][date] = mark;
        dates.insert(date);
    }
    cout << ".";
    for (const auto &elem: dates) {
        cout << " " << elem;
    }
    for (auto& [key, mapkey] : m) {
        cout << "\n";
        cout << key;
        for (const auto& elem: dates) {
            if (mapkey.find(elem) != mapkey.end()) {
                cout << " " << mapkey[elem];
            } else {
                cout << " .";
            }
        }
    }
}