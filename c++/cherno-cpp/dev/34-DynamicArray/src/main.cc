#include "dynamic_array.h"
#include <iostream>

struct Vector3 {
    float x = 0.0f, y = 0.0f, z = 0.0f;

    Vector3() { }
    Vector3(float scalar)
        : x { scalar }
        , y { scalar }
        , z { scalar }
    {
    }

    Vector3(float x, float y, float z)
        : x { x }
        , y { y }
        , z { z }
    {
    }

    Vector3(const Vector3& other)
        : x { other.x }
        , y { other.y }
        , z { other.z }
    {
        std::cout << "Copy\n";
    }

    Vector3(const Vector3&& other)
        : x { other.x }
        , y { other.y }
        , z { other.z }
    {
        std::cout << "Move\n";
    }

    Vector3& operator=(const Vector3& other)
    {
        std::cout << "Copy\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vector3& operator=(const Vector3&& other)
    {
        std::cout << "Move\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, Vector3& v) { return os << "( " << v.x << ", " << v.y << ", " << v.z << ")"; }
    friend std::ostream& operator<<(std::ostream& os, const Vector3& v) { return os << "( " << v.x << ", " << v.y << ", " << v.z << ")"; }

    ~Vector3() { std::cout << "Destroy\n"; }
};

template class DynamicArr<Vector3>;

template <typename T> void print_vect(const DynamicArr<T> darr)
{
    int N = darr.Size();
    for (int i = 0; i < N; i++)
        std::cout << darr[i] << " ";
    std::cout << "\n";
}

int main()
{
    int N = 10;
    DynamicArr<int> darr;
    for (int i = 0; i < N; i++)
        darr.PushBack(i);

    DynamicArr<Vector3> darr2;
    darr2.PushBack(Vector3(1.0f));
    darr2.PushBack(Vector3(2, 3, 4));
    darr2.PushBack(Vector3());
    darr2.EmplaceBack(1, 2, 3);
    darr2.EmplaceBack(10, 20, 30);

    print_vect(darr2);

    std::cin.get();
}
