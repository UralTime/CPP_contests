enum { TASK_LIMIT = 5 };

template<typename T>
typename T::value_type process(const T& obj)
{
    typename T::value_type sum{};
    int cnt = 1;
    for (auto it = obj.rbegin(); it != obj.rend() && cnt <= TASK_LIMIT; it++, cnt++) {
        if (cnt & 1) {
            sum += *it;
        }
    }
    return sum;
}