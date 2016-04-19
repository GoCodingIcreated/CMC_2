#include <iostream>
#include <map>
#include <thread>
#include <mutex>
#include <vector>
#include <fstream>
std::mutex m;
std::map<std::string, int> global_map;
void work(char *file) {
    std::ifstream in(file);
    std::string str;
    while (in >> str) {
        m.lock();
        if (global_map.find(str) != global_map.end()) {
            ++global_map[str];
        }
        else {
            global_map[str] = 1;
        }
        m.unlock();
    }
}

int main(int argc, char **argv) {
    std::vector<std::thread> v;
    for (int i = 1; i < argc; ++i) {
        v.emplace_back(work, argv[i]);
    }
    std::cout << global_map.size() << std::endl;
    for (auto it = global_map.begin(); it != global_map.end(); ++it) {
        std::cout << it->first << ' ' << it->second << std::endl;
    }
}
