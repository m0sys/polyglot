#include <iostream>
#include <vector>

void helloWorld(int a) { std::cout << "Hello, World! Value: " << a << std::endl; }

void printVal(int val) { std::cout << "Value: " << val << std::endl; }

void forEach(const std::vector<int>& vals, void (*func)(int))
{
    for (int val : vals)
        func(val);
}

int main()
{
    auto func = helloWorld;
    func(2);

    // Higher Order function.
    std::vector<int> vals = { 2, 4, 6, 8, 10 };
    forEach(vals, printVal);

    // Using lambdas.
    forEach(vals, [](int val) { std::cout << "Value with Lambda: " << val << std::endl; });
    std::cin.get();
}
