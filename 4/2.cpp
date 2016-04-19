class C
{
    int x;
public:
    C(int x) : x(2 * x) { }
    C(const C &c) : x(c.x) { }
    int get() const {
        return x;
    }
    C operator+(const C c) const {
        return C(x + c.x);
    }
};
