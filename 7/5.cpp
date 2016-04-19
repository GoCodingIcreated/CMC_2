#include <iostream>
#include <map>
#include <thread>
#include <mutex>
#include <vector>
#include <fstream>
#include <algorithm>
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
    in.close();
}

bool cmp(const std::pair<int, std::string>  &a, const std::pair<int, std::string> &b) {
    return a.first == b.first ? a.second < b.second : a.first > b.first;
}

int main(int argc, char **argv) {
    std::vector<std::thread> v;
    std::string str;
    for (int i = 1; i < argc; ++i) {
        v.emplace_back(work, argv[i]);
    }
    for (auto it = v.begin(); it != v.end(); ++it) {
        it->join();
    }
    std::vector<std::pair<int, std::string> > ans_v;
    for (auto it = global_map.begin(); it != global_map.end(); ++it) {
        ans_v.push_back(std::make_pair(it->second, it->first));
    }
    std::sort(ans_v.begin(), ans_v.end(), cmp);
    int cnt = 20;
    std::cout << ans_v.size() << std::endl;
    for (auto it = ans_v.begin(); it != ans_v.end() && cnt > 0; ++it, --cnt) {
        std::cout << it->second << ' ' << it->first << std::endl;
    }
}
