#include <iostream>
#include <vector>
void process(const std::vector<int> &v1, std::vector<int> &v2) {
    auto it_v2 = v2.begin();
    size_t end = v2.size();
    size_t counter = 0;
    for (auto i = v1.begin(); i != v1.end() && it_v2 != v2.begin() + end; ++i, ++it_v2, ++counter) {
        if (*i > *it_v2) {
            v2.push_back(*i);
            it_v2 = v2.begin() + counter;
        }
    }
    for (auto i = v2.begin(); i != v2.end(); ++i) {
        std::cout << *i << ' ';
    }
}
