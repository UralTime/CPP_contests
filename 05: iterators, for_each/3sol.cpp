#include <vector>
#include <algorithm>

void process (const std::vector<int> &v, std::vector<int> &v2) 
{
    if (v.empty() || v2.empty()) {
        return;
    }
    std::vector<int> v1 = v;
    std::sort(v1.begin(), v1.end());
    auto last = std::unique(v1.begin(), v1.end());
    v1.erase(last, v1.end());
    auto it2 = v2.begin(), it22 = v2.begin();
    auto it1 = v1.begin();
    while (*it1 < 0) {
        it1++;
        if (it1 == v1.end()) {
            return;
        }
    }
    int pos = 0, size = v2.size();
    while (it1 != v1.end() && it22 != v2.end() && size > *it1) {
        for (int i = pos; i < *it1; ++i) {
            *(it2++) = *(it22++); 
        }
        pos = *(it1++);
        pos++;
        it22++;
    }
    while (it22 != v2.end()) {
        *(it2++) = *(it22++); 
    }
    v2.erase(it2, v2.end());
}