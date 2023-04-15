#include <cstdio>
#include <cstring>
using std::size_t;
class Arena {
public:
    Item *mas;
    bool *free;
    size_t count;

    Arena(const Arena&) = delete;
    Arena& operator=(const Arena&) = delete;
    
    explicit Arena(size_t size) {
            count = size / sizeof(Item);
            mas = new Item[count];
            free = new bool[count];
            std::memset(free, true, count);
    }
    
    Item *get() {
        for (size_t i = 0; i < count; i++) {
            if (free[i]) {
                free[i] = false;
                return &mas[i];
            }
        }
        return nullptr;
    }
    
    void put(Item *item) {
        free[item - mas] = true;
    }
    
    ~Arena() {
        delete[] mas;
        delete[] free;
    }
};