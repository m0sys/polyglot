#include <iostream>
#include <string>

using String = std::string;

class Entity {
private:
    String m_Name;
    int m_Age;

public:
    Entity()
        : m_Name("Unknown")
    {
    }
    Entity(const String& name)
        : m_Name(name)
        , m_Age(-1)
    {
    }

    // Inforce explicit construction.
    explicit Entity(const int age)
        : m_Name("Unknown")
        , m_Age(age)
    {
    }

    const String& GetName() const { return m_Name; }
};

void Function() { Entity entity = Entity("Moe"); }

int main()
{
    // Init in stack mem.
    Entity* e;
    {
        Entity entity("Moe");
        e = &entity;
        std::cout << entity.GetName() << std::endl;
        std::cout << e->GetName() << std::endl;
    }
    std::cout << e->GetName() << std::endl;

    // Init in heap mem.
    {
        Entity* entity = new Entity("Moe");
        std::cout << entity->GetName() << std::endl;
        delete entity;
    }
    // NOTE: allocating to heap mem requires manual deallocation. It is also
    //       less optimized than allocating to stack mem.

    // The `new` keyword.
    int* c = new int[50]; // 200 bytes
    delete[] c;

    // Implicit conversion.
    Entity a = String("Cherno");
    Entity b(22);

    std::cin.get();
}
