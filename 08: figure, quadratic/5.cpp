#include <complex>
#include <array>
#include <vector>
#include <limits>
#include <cmath>
namespace Equations
{
    template<typename T>
    auto quadratic(std::array<std::complex<T>, 3> vv)
    {
        using std::pair;
        using std::vector;
        using std::complex;
        using std::norm;
        complex<T> a = vv[2], b = vv[1], c = vv[0];
        T EPS = std::numeric_limits<T>::epsilon() * 32.0;
        if (norm(a) < EPS) {
            if (norm(b) < EPS) {
                if (norm(c) < EPS) {
                    vector<complex<T>> v;
                    pair<bool, vector<complex<T>>> p{false, v};
                    return p;
                } else {
                    vector<complex<T>> v;
                    pair<bool, vector<complex<T>>> p{true, v};
                    return p;
                }
            } else {
                vector<complex<T>> v;
                v.push_back(-c / b);
                pair<bool, vector<complex<T>>> p{true, v};
                return p;
            }
        } else {
            constexpr complex<T> four(4, 0), two(2, 0);
            complex<T> discriminant = b * b - four * a * c;
            if (norm(discriminant) < EPS) {
                vector<complex<T>> v;
                v.push_back(-b / (two * a));
                v.push_back(-b / (two * a));
                pair<bool, vector<complex<T>>> p{true, v};
                return p;                
            } else {
                complex<T> discr_sqrt = std::sqrt(discriminant);
                vector<complex<T>> v;
                v.push_back((-b + discr_sqrt) / (two * a));
                v.push_back((-b - discr_sqrt) / (two * a));
                pair<bool, vector<complex<T>>> p{true, v};
                return p; 
            }
        }
    };
}