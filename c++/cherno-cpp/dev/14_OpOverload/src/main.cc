#include <iostream>

struct Vector2 {
    float x, y;
    Vector2(float x, float y)
        : x(x)
        , y(y)
    {
    }

    Vector2 Add(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }

    Vector2 operator+(const Vector2& other) const { return Add(other); }

    Vector2 Mult(const Vector2& other) const { return Vector2(x * other.x, y * other.y); }

    Vector2 operator*(const Vector2& other) const { return Mult(other); }

    bool operator==(const Vector2& other) const { return x == other.x && y == other.y; }

    bool operator!=(const Vector2& other) const { return !(*this == other); }
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
    stream << other.x << ", " << other.y;
    return stream;
}

int main()
{
    Vector2 pos(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 2.0f);
    Vector2 res = pos.Add(speed);
    Vector2 res2 = pos + speed * powerup;

    std::cout << res << std::endl;
    std::cout << res2 << std::endl;
    std::cout << (res == res2) << std::endl;
    std::cout << (res != res2) << std::endl;
    std::cin.get();
}
