class B
{
    int x, y;
public:
    B(int x, int y = 3) {
        this->x = x;
        this->y = y;
    }
    B& operator+=(const B& b) {
        x += b.x;
        y += b.y;
        return *this;
    }
    int get() const {
        return x + y;
    }
};
