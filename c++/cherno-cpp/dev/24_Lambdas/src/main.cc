#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

void forEach(const std::vector<int>& vals, const std::function<void(int)>& func)
{
    for (int val : vals)
        func(val);
}

int main()
{
    // Higher Order function.
    std::vector<int> vals = { 2, 4, 6, 8, 10 };
    auto it = std::find_if(vals.begin(), vals.end(), [](int val) { return val > 3; });
    std::cout << *it << std::endl;

    int a = 5;
    forEach(vals, [=](int val) { std::cout << "Value with Lambda: " << val * a << std::endl; });
    std::cin.get();
}
