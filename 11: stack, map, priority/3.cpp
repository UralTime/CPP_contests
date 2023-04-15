#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cctype>

int main()
{
    std::map<char, std::vector<std::pair<std::string, bool>>> rules;
    char left;
    std::string right;
    while (std::cin >> left >> right) {
        auto it = rules.find(left);
        auto rule = std::pair(right, false);
        if (it != rules.end()) {
            it->second.emplace_back(std::move(rule));
        } else {
            rules.emplace(left, std::vector{std::move(rule)});
        }
    }
    std::set<char> prev;
    std::set<char> next{'S'};
    do {
        prev = next;
        next = {};
        for (char cur : prev) {                       
            if (rules.find(cur) != rules.end()) {      
                for (auto& [str, flag] : rules[cur]) { 
                    if (flag == false) { 
                        flag = true;
                        for (char s : str) { 
                            if (isupper(s) && prev.find(s) == prev.end()) {
                                next.insert(s); 
                            }
                        }
                    }
                }
            }
        }
    } while (next.size() != 0);
    for (auto& el : rules) {
        for (auto& [str, flag] : el.second) {
            if (flag) {
                std::cout << el.first << ' ' << str << std::endl;
            }
        }
    }
}