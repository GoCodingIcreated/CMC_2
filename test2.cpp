#include <iostream>
class A
{
public:
    int a;
};

class B : private A 
{
    void f() { std::cout << a; }
};
