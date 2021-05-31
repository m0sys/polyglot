#include <iostream>
#define LOG(x) std::cout << x << std::endl;

class Entity {
public:
    float X, Y;
    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }
};

class Player : public Entity {
public:
    const char* Name;
    void PrintName() { LOG(Name); }
};

int main()
{
    LOG("Hello, World!");

    LOG(sizeof(Entity));
    LOG(sizeof(Player));

    Player player = Player();
    player.Move(5, 10);
    player.PrintName();
    std::cin.get();
}
