#include <vector>
#include <cstdint>

void process (const std::vector<uint64_t> &v1, std::vector<uint64_t> &v2, uint64_t param) {
    auto i1 = v1.begin();
    for (auto i2 = v2.rbegin(); i1 < v1.end() && i2 < v2.rend(); ++i2, i1 += param) {
        *i2 += *i1;
    }
}