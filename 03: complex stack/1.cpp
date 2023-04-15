#include <cmath>
#include <string>
#include <cstdio>
#include <iomanip>

namespace numbers 
{
    class complex
    {
        double x, y;
    public:
        complex (double r = 0.0, double i = 0.0): x(r), y(i) {}
        complex (const complex &other): x(other.x), y(other.y) {}
        explicit complex (const std::string &str) {
            sscanf(str.c_str(), "(%lf,%lf)", &x, &y);
        }

        double abs2 () const {
            return x * x + y * y;
        }
        double abs () const {
            return sqrt(x * x + y * y);
        }
        double re () const {
            return x;
        }
        double im () const {
            return y;
        }

        complex operator ~ () const {
            return complex(x, -y);
        }
        complex operator - () const {
            return complex(-x, -y);
        }

        const complex& operator += (const complex &other) {
            x += other.x;
            y += other.y;
            return *this;
        }
        const complex& operator -= (const complex &other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }
        const complex& operator *= (const complex &other) {
            double tmp = x * other.x - y * other.y;
            y = y * other.x + x * other.y;
            x = tmp;
            return *this;
        }
        const complex& operator /= (const complex &other) {
            double abs2 = other.abs2();
            double tmp = (x * other.x + y * other.y) / abs2;
            y = (y * other.x - x * other.y) / abs2;
            x = tmp;
            return *this;
        }

        std::string to_string () const {
            std::stringstream stream;
            stream << std::setprecision(10) << '(' << x << ',' << y << ')';
            return stream.str();
        }
    };

    inline complex operator + (complex C, complex S) {
        return C += S;
    }
    inline complex operator - (complex C, complex S) {
        return C -= S;
    }
    inline complex operator * (complex C, complex S) {
        return C *= S;
    }
    inline complex operator / (complex C, complex S) {
        return C /= S;
    }
}