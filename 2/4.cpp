#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>

namespace numbers
{
	class complex
	{
		double re, im;
	public:
		complex(double r = 0, double i = 0) : re(r), im(i) {
			re = r, im = i;
		}
		explicit complex(const char *str) : re(0), im(0) {
			sscanf(str, "(%lf,%lf)", &re, &im);
		}
		double get_re() const {
			return re;
		}
		double get_im() const {
			return im;
		}
		double abs2() const {
			return re * re + im * im;
		}
		double abs() const {
			return pow(abs2(), 0.5);
		}
		friend complex operator+(complex, complex);
		friend complex operator-(complex, complex);
		friend complex operator*(complex, complex);
		friend complex operator/(complex, complex);
		complex operator~() const {
			return complex(re, -im);
		}
		complex operator-() const {
			return complex(-re, -im);
		}
		void to_string(char *buf, size_t size) const {
			sprintf(buf, "(%.10g,%.10g)", re, im);
		}
	};
	complex operator+(complex a, complex b) {
		return complex(a.re + b.re, a.im + b.im);
	}
	complex operator-(complex a, complex b) {
		return complex(a.re - b.re, a.im - b.im);
	}
	complex operator*(complex a, complex b) {
		return complex(a.re * b.re - a.im * b.im, b.re * a.im + b.im * a.re);
	}
	complex operator/(complex a, complex b) {
		return complex((a.re * b.re + a.im * b.im) / b.abs2(), (b.re * a.im - a.re * b.im) / b.abs2());
	}
    
    class complex_stack
    {
        complex* stack;
        size_t max_size;
        size_t cur_size;
        void extend() {
            max_size <<= 1;
            char *buffer = new char[max_size * sizeof(complex)];
            complex* stack2 = new (buffer) complex[max_size];
            for (size_t i = 0; i < cur_size; ++i) {
                stack2[i] = complex(stack[i]);
            }
            delete[] stack;
            stack = stack2;
        }
        void stack_swap(complex_stack &s1, complex_stack &s2) {
            std::swap(s1.stack, s2.stack);
            std::swap(s1.max_size, s2.max_size);
            std::swap(s1.cur_size, s2.cur_size);
        }
    public:
        complex_stack& operator=(const complex_stack &st) {
            complex_stack tmp = st;
            stack_swap(*this, tmp);
            return *this;
        }
        complex_stack() : stack(NULL), max_size(10), cur_size(0) {
            //max_size = 10;
            //cur_size = 0;
            stack = new complex[max_size];
        }
        complex_stack(const complex_stack &st) {
            max_size = st.max_size;
            cur_size = st.cur_size;
            char *buffer = new char[max_size * sizeof(complex)];
            stack = new (buffer) complex[max_size];
            for (size_t i = 0; i < cur_size; ++i) {
                stack[i] = complex(st.stack[i]);
            }
        }
        ~complex_stack() {
            delete[] stack;
        }
        size_t size() const {
            return cur_size;
        }
        complex& operator[](int i) {
            return stack[i];
        }
        friend complex_stack operator<<(complex_stack, complex);
        complex operator+() const {
            return stack[cur_size - 1];
        }
        complex_stack operator~() const {
            complex_stack a = *this;
            a.cur_size--;
            return a;
        }	

    };
    inline complex_stack operator<<(complex_stack st, complex a) {
        if (st.cur_size == st.max_size)
            st.extend();
        st.stack[st.cur_size++] = a;
        return st;
    }

    complex eval(char **argv, const complex &z)
    {
        complex_stack stack;
        char *cur_arg = *argv;
        while (cur_arg != NULL) {
            if (cur_arg[0] == '+') {
                complex tmp = +stack;
                stack = ~stack;
                tmp = tmp + +stack;
                stack[stack.size() - 1] = tmp;
            }
            else if (cur_arg[0] == '-') {
                complex tmp = +stack;
                stack = ~stack;
                tmp = +stack - tmp;
                stack[stack.size() - 1] = tmp;
            }
            else if (cur_arg[0] == '*') {
                complex tmp = +stack;
                stack = ~stack;
                tmp = tmp * +stack;
                stack[stack.size() - 1] = tmp;
            }
            else if (cur_arg[0] == '/') {
                complex tmp = +stack;
                stack = ~stack;
                tmp = +stack / tmp;
                stack[stack.size() - 1] = tmp;
            }
            else if (cur_arg[0] == '(') {
                stack = stack << complex(cur_arg);
            }
            else if (cur_arg[0] == 'z') {
                stack = stack << z;
            }
            else if (cur_arg[0] == '!') {
                stack = stack << +stack;
            }
            else if (cur_arg[0] == ';') {
                stack = ~stack;
            }
            else if (cur_arg[0] == '~') {
                complex tmp = ~+stack;
                stack[stack.size() - 1] = tmp;
            }
            else if (cur_arg[0] == '#') {
                complex tmp = -+stack;
                stack[stack.size() - 1] = tmp;
            }
            argv++;
            cur_arg = *argv;
        }
        return +stack;
    }
}

using namespace numbers;
int main(int argc, char ** argv) {
    complex c = complex(argv[1]);
    double R;
    sscanf(argv[2], "%lf", &R);
    int N;
    sscanf(argv[3], "%d", &N);
    complex I = 0;
    complex cur = c + complex(0, R);
    complex turn1(cos(M_PI / N), sin(M_PI / N));
    complex turn2(cos(2 * M_PI / N), sin(2 * M_PI / N));
    char buffer[1024];
    for (int i = 0; i < N; ++i) {
        complex z = eval(argv + 4, c + (cur - c) * turn1);
        complex new_cur = c + (cur - c) * turn2;
        I = I + z * (new_cur - cur);
        cur = new_cur;
    }
    I.to_string(buffer, sizeof(buffer));
    std::cout << buffer << std::endl;
}
