#include <iostream>
class C
{
    int cc = 0;
public:
    C (int c) { cc = 2 * c; };
    int get () const { return cc; }
            const C& operator += (C &other) {
            cc += other.cc;
            cc *= 2;
            return *this;
        }
};
    inline C operator + (C CC, C S) {
        return CC += S;
    };
using std::cout;
using std::endl;