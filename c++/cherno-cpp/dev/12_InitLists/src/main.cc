#include <iostream>

class Example {
public:
    Example() { std::cout << "Created Entity!" << std::endl; }

    Example(int x) { std::cout << "Created Entity!" << x << std::endl; }
};

class Entity {
private:
    Example m_Example; // #1
    std::string m_Name;

public:
    Entity()
        : m_Example(8)
        , m_Name("Unknown")
    {
        // m_Example = Example(8); // #2 - this will cause Example to init twice.
    }

    Entity(const std::string& name)
        : m_Name(name)
    {
    }
};

int main()
{
    Entity e;
    std::cin.get();
}
