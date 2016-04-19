#include <iostream>
#include <algorithm>
#include <vector>

class AvgSum {
    double sum;
public:
    AvgSum() {
        sum = 0;
    }
    void operator() (double x) {
        sum += x;
    }
    double get() const {
        return sum;
    }
};
int main() {
    std::vector<double> vec;
    double x;
    AvgSum avg_sum;
    while (std::cin >> x) {
        vec.push_back(x);
    }
    int n = vec.size() * 0.1;
    std::sort(vec.begin() + n, vec.end() - n);
    int m = (vec.size() - 2 * n) * 0.1;
    avg_sum = std::for_each(vec.begin() + n + m, vec.end() - n - m, avg_sum);
    std::cout.precision(10);
    std::cout << avg_sum.get() / (vec.size() - 2 * (n + m)) << std::endl;
}
