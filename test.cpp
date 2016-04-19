#include <iostream>
#include <vector>
#include <algorithm>
class Figure {

    int x;
public:
    int get_square() const {
        return x;
    }
    Figure(int x, int y) {
        this->x = x;
    }
    bool operator<(const Figure &a) {
        return x < a.x;
    }
};

struct my_tcmp
{
    bool operator() (const Figure& A1, const Figure& A2) {
        return A1.get_square() < A2.get_square();
    }
} my_cmp;

int main()
{
//вернуть паблик после конструктора создания
    char type;
    std::vector <Figure> V;
    std::sort(V.begin(),V.end(), my_cmp);
}
