template <class T, class P>
T myfilter(T container, P predicat) 
{
    T new_container{};
    for (const auto &x : container) {
        if (predicat(x)) {
            new_container.insert(new_container.end(), x);
        }
    }
    return new_container;
}