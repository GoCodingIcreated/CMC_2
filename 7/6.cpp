#include <iostream>
#include <thread>
#include <queue>
#include <mutex>

std::mutex m;
int is_over = 0;
std::queue<std::pair<int,int> > tasks;
std::vector<int> for_print;
void work() {
    while (is_over == 0) {
        m.lock();
        if (!tasks.empty()) {
            auto t = tasks.front();
            tasks.pop();
            for_print.emplace_back(t.first + t.second);
        }
        m.unlock();
    }
}

void print() {
    for (auto it = for_print.begin(); it != for_print.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    int x, y;
    std::thread worker1(work), worker2(work);
    while (std::cin >> x >> y) {
        tasks.push(std::make_pair(x, y));
    }
    is_over = 1;
    worker1.join();
    worker2.join();
    std::thread printer(print);
    printer.join();
}
