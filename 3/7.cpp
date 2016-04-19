#include <iostream>
class C
{
    int x;
public:
    C(double x = 0) {
        this->x = x;
    }
    C(int a, int b) {
        this->x = a + b;
    }
    const C& operator++() {
        x++;
        return *this;
    }
    int operator*(const C *c) const {
        return x * c->x;
    }
    C operator&() const {
        return *this;
    }
    int operator~() const {
        return -x;
    }
    friend int operator+(int, const C&);
};
int operator+(int x, const C &c) {
    return x + c.x;
}
