#include <iostream>
#include <vector>
int main() {
    std::vector<int> v {1, 2, 3};
    std::cout << *((v.rbegin()).base() - 1);
}
