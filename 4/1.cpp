#include <cstdio>
struct S
{
    int x;
    S(int n)
    {
        x = n;
        printf("a\n");
    }
    S(const S &a)
    {
        x = a.x;
        printf("b\n");
    }
    ~S()
    {
        printf("c\n");
    }
};
S f(S &y)
{
    y = S(3);
    return y;
}
int main() {
    S s(1);
    f(s);
    printf("%d\n", s.x);
    return 0;
}
