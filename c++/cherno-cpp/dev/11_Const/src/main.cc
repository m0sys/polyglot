#include <iostream>

class Entity {
private:
    int m_X, m_Y;

public:
    int GetX() const { return m_X; }

    void Set(int x) { m_X = x; }
};

int main()
{
    const int MAX_AGE = 90;
    // Both content and what it points at is constant.
    const int* const a = new int;

    // *a = 2;
    // a = (int*)&MAX_AGE;

    // a = nullptr;
    std::cout << MAX_AGE << std::endl;
    std::cout << *a << std::endl;

    const Entity e = Entity();
    e.GetX();

    int x = 8;
    auto f = [=]() mutable {
        x++;
        std::cout << x << std::endl;
    };

    f();

    std::cin.get();
}
