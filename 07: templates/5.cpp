#include <algorithm>

template <typename type_arr, class F>
void selection_sort(type_arr begin, type_arr end, F cmp)
{
    for (auto i = begin; i != end; ++i) {
        auto min_index = i;
        for (auto j = i + 1; j != end; ++j) {
            if (cmp(*j, *min_index)) {
                min_index = j;
            }
        }
        if (min_index != i) {
            iter_swap(i, min_index);
        }
    }
}

template <typename type_arr>
void selection_sort(type_arr begin, type_arr end)
{
    for (auto i = begin; i != end; ++i) {
        auto min_index = i;
        for (auto j = i + 1; j != end; ++j) {
            if (*j < *min_index) {
                min_index = j;
            }
        }
        if (min_index != i) {
            iter_swap(i, min_index);
        }
    }
}