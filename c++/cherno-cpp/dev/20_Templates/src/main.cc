#include <iostream>
#include <string>

template <typename T> void Print(T value) { std::cout << value << std::endl; }

template <typename T, int N> class Array {
private:
    T m_Array[N];

public:
    int GetSize() const { return N; }
};

int main()
{
    Print(5);
    Print("Hello");
    Print(5.5f);

    Array<int, 5> array;
    std::cout << array.GetSize() << std::endl;

    std::cin.get();
}
