#include <iostream>

// NOTE: each time the template is called - a hard coded version with
// appropriate typename and size_t is created by the compiler.

template <typename T, size_t S> class Array {
public:
    constexpr size_t Size() const { return S; }
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

private:
    T data[S];
};

int main()
{
    Array<int, 9> data;
    static_assert(data.Size() < 10, "Size is too large!");

    for (size_t i = 0; i < data.Size(); i++) {

        data[i] = i;
        std::cout << data[i] << "\n";
    }
}
