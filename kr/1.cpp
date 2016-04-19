#include <iostream>

int main() {
    char ch;
    int count = 0;
    char current_char = 0;
    while (std::cin.get(ch)) {
        if (ch == current_char) {
            ++count;
        }
        else {
            if (count > 4 || current_char == '#') {
                std::cout << '#' << current_char << std::hex << count << '#';
            }
            else {
                for (int i = 0; i < count; ++i) {
                    std::cout << current_char;
                }
            }
            count = 1;
            current_char = ch;
        }
    }
    if (count > 4 || current_char == '#') {
        std::cout << '#' << std::hex << current_char << count << '#';
    }
    else {
        for (int i = 0; i < count; ++i) {
            std::cout << current_char;
        }
    }
}
