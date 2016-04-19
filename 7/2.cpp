#include <iostream>

int main() {
    std::string str;
    while (std::cin >> str) {
        int state = 0;
        for (int i = 0; i < (int)str.size(); ++i) {
            if (str[i] < '1' || str[i] > '4') {
                state = -1;
                break;
            }
            if (state != 0 && (str[i] == '3' || str[i] == '4')) {
                state = -1;
                break;
            }
            if (state == 0 && (str[i] == '1' || str[i] == '2')) {
                state = 1;
            }
        }
        if (state == -1) {
            std::cout << 0 << std::endl;
        }
        else {
            std::cout << 1 << std::endl;
        }
    }
}
