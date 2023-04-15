#include <vector>
#include <iterator>
#include <functional>

template <class T, class F>
void myapply (T it_begin, T it_end, F func)
{
    for (T it = it_begin; it != it_end; ++it) {
        func(*it);
    }
}

template <class T, class F>
auto myfilter2 (T it_begin, T it_end, F pred)
{
    std::vector<typename std::reference_wrapper<typename std::iterator_traits<T>::value_type>> res;
    for (T it = it_begin; it != it_end; it++) {
        if (pred(*it)) {
            res.push_back(std::ref(*it));
        }
    }
    return res;
}