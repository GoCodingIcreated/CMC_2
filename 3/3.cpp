#include <iostream>
#include <string>
#include <algorithm>
int main() {
    std::string str, str2;
    while (std::cin >> str) {
        for (int i = str.size(); i > 0; --i) {
            str2 = str.substr(0, i);
            std::reverse(str2.begin(), str2.end());
            if (str.compare(0, i, str2) == 0) {
                std::cout << str.substr(0, i) << std::endl;
                break;
            }
        }
    }
}
