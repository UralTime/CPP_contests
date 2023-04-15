class C
{
public:
    C () {};
    C (double d) {};
    C (double a, double b) {};
    C (const C*) {};
    int operator * (C* c) { return 0; };
    C operator ++ () { return *this; };
    int operator ~ () const { return 0; };
};
 
inline int operator + (int v2, const C& v1) { return 0; }
