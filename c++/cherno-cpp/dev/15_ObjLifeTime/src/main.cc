#include <iostream>

class Entity {
public:
    Entity() { std::cout << "Created Entity!" << std::endl; }

    ~Entity() { std::cout << "Destroyed Entity!" << std::endl; }
};

class ScopedPtr {
private:
    Entity* m_Ptr;

public:
    ScopedPtr(Entity* ptr)
        : m_Ptr(ptr)
    {
    }

    ~ScopedPtr() { delete m_Ptr; }
};

int main()
{
    // This entity will get destroyed as soon as the program is outside the scope.
    // If it were allocatd on the heap instead then it would be destroyed by the OS
    // if not deleted in the program itself.
    {
        ScopedPtr e = new Entity();
    }

    std::cin.get();
}
