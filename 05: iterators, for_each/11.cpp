#include <vector>
#include <cstdint>
#include <iterator>
using std::vector;

void process(const vector<uint64_t> v1, vector<uint64_t> &v2, uint64_t step){
    if (v1.empty() || v2.empty()) return;
    auto dest = v2.rbegin();
    auto src = v1.begin();
    while (dest != v2.rend() && src != v1.end()) {
        *dest += *src;
        ++dest;
        auto diff = std::distance(src, v1.end());
        auto minim = 0;
        if (step < diff) minim = step; else minim = diff;
        for (auto i = 0; i < minim && src != v1.end(); i++) {
            src++;
        }
    }
}