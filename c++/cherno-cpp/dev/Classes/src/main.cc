#include <iostream>
#include "log.cc"

enum Example : unsigned char 
{
    A, B, C
};

struct Entity
{
    static int x, y;
    void Print() {
        std::cout << x << ", " << y << std::endl;
    }
};

int Entity::x;
int Entity::y;

void Function() {
    // This makes it function like a closure.
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

class Entity2
{
public:
    int X, Y;

    Entity2() 
    {
        X = 0;
        Y = 0;
    }

    Entity2(float x, float y) 
    {
        X = x;
        Y = y;
    }

    ~Entity2() 
    {
        std::cout <<"Destroyed Entity!" << std::endl;
    }
    void Print() {
        std::cout << X << ", " << Y << std::endl;
    }
};

int main() {
    Entity e;
    Entity::x = 2;
    Entity::y = 3;
    Entity e1;

    Entity::x = 5;
    Entity::y = 8;
    e.Print();
    e1.Print();

    Function();
    Function();
    Function();
    Function();

    Log log;
    log.SetLevel(Log::LevelError);
    log.Error("Hello!");
    log.Warn("Hello!");
    log.Info("Hello!");

    Entity2 e2;
    e2.Print();

    std::cin.get();
}
