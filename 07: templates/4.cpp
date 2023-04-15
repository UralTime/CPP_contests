#include <vector>
#include <algorithm>

template <class Ind, class Obj>
Obj myremove (Ind it_begin, Ind it_end, Obj obj_begin, Obj obj_end)
{
    std::vector<int> v1 {};
    for (Ind it = it_begin; it != it_end; it++) {
        v1.emplace_back(*it);
    }
    std::sort(v1.begin(), v1.end());
    auto last = std::unique(v1.begin(), v1.end());
    v1.erase(last, v1.end());
    auto it_indices = v1.begin();
    while (*it_indices < 0) {
        it_indices++;
        if (it_indices == v1.end()) {
            return obj_end;
        }
    }
    
    Obj it_obj = obj_begin, new_it_obj = obj_begin;
    int pos = 0, size = std::distance(obj_begin, obj_end);
    while (it_indices != v1.end() && it_obj != obj_end && size > *it_indices) {
        for (int i = pos; i < *it_indices; ++i) {
            std::swap(*(it_obj++), *(new_it_obj++)); 
        }
        pos = *it_indices;
        ++it_indices;
        ++it_obj;
        ++pos;
    }

    while (it_obj != obj_end) {
        std::swap(*(it_obj++), *(new_it_obj++)); 
    }

    return new_it_obj;
}