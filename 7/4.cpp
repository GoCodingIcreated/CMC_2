#include <iostream>
#include <vector>

struct Student {
    std::string name;
    std::string file_name;
    std::vector<int> marks;
    int sum;
    Student(std::string name_, const char *file) : name(name_), file_name(file), sum(0) {}
};

int main(int argc, char **argv) {
    std::string name;
    vector<Student> students;
    int sum = 0;
    for (int i = 1; i < argc; ++i) {
        istream in(argv[i]);
        while (in >> name) {
            int mark;
            students.push_back(Student(name, argv[i]));
            auto it = students.end() - 1;
            in >> mark;
            while (mark != 0) {
                it->marks.push_back(mark);
                it->sum += mark;
            }
            sum += (double)it->sum / it->marks.size();
        }
    }
}
