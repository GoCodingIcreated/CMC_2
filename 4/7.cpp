#include <string>
#include <algorithm>
#include <iostream>
class BinaryNumber
{
    std::string str;
public:
    BinaryNumber(const std::string &s) {
        str = s;
    }
    operator std::string() const {
        return str;
    }
    const BinaryNumber &operator++() {
        bool need_resize = true;
        for (size_t i = str.size() - 1; i >= 0; --i) {
            if (str[i] == '0') {
                str[i] = '1';
                need_resize = false;
                break;
            }
            str[i] = '0';
            if (i == 0) {
                break;
            }
        }
        if (need_resize) {
            //str = "1" + str;
            std::reverse(str.begin(), str.end());
            str += "1";
            std::reverse(str.begin(), str.end());
        }
        return *this;
    }
};
/*
int main() {
    std::string s = "0";
    BinaryNumber bn(s);
    //++bn, ++bn, ++bn, ++bn;
    for (unsigned  i = 0; i < 100; ++i ) {
        std::cout << std::string(++bn) << std::endl;
    }
}*/

