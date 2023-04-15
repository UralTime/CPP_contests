#include <string>
using std::string;

class BinaryNumber
{
    string num;
public:
    BinaryNumber(const string &s) {
        num = s;
    };
    operator string () const {
        return num;
    };
    const BinaryNumber &operator++() {
        size_t pos = -1, last_pos = num.length() - 1;
        string begin = "";
        if (num.rfind('0') != string::npos) {
            pos = num.rfind('0');
            begin = num.erase(pos, last_pos);
        }
        num = begin + '1' + string(last_pos - pos, '0');
        return *this;
    };
};