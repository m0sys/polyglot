#include "linear_map.h"
#include <iostream>
#include <string>
#include <utility>

// 7.3.2. String Literals

// Requires built-in speaker which most modern computers no longer have.
void beep_boop_bop() { std::cout << "beep\a boop bop - starwars edition bruh\a\a\a\n"; }

// 7.4.3. Passing Arrays

void print_mij(int* m, int dim1, int dim2)
{
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++)
            std::cout << m[i * dim2 + j] << '\t';
        std::cout << '\n';
    }
}

void test_print_mij()
{
    int v[3][5] = { { 0, 1, 2, 3, 4 }, { 10, 11, 12, 13, 14 }, { 20, 21, 22, 23, 24 } };

    print_mij(&v[0][0], 3, 5);
}

// 7.7.1. Lvalue References

void test_linear_map()
{
    using namespace std;
    LinearMap<string, int> buf;
    for (string s; cin >> s;)
        ++buf[s];

    for (const auto& x : buf)
        cout << x.first << ": " << x.second << '\n';
}

template <class T> void swap(T& a, T& b) // near perfect swap
{
    T tmp { static_cast<T&&>(a) };
    a = static_cast<T&&>(b);
    b = static_cast<T&&>(tmp);
}

template <class T> void swap2(T& a, T& b) // near perfect swap
{
    // move === static_cast<T&&> but way less error prone and shorter.
    using namespace std;
    T tmp { move(a) };
    a = move(b);
    b = move(tmp);
}

int main()
{
    beep_boop_bop();
    test_print_mij();
    test_linear_map();

    std::cin.get();
}
