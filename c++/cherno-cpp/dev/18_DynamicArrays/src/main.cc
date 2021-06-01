#include <iostream>
#include <string>
#include <vector>

struct Vertex {
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x)
        , y(y)
        , z(z)
    {
    }

    Vertex(const Vertex& other)
        : x(other.x)
        , y(other.x)
        , z(other.z)
    {
        std::cout << "Copied!" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

void IntroToArrays()
{
    std::vector<Vertex> vertices;
    vertices.push_back({ 1, 2, 3 });
    vertices.push_back({ 4, 5, 6 });

    for (int i = 0; i < int(vertices.size()); i++)
        std::cout << vertices[i] << std::endl;

    for (const Vertex& v : vertices)
        std::cout << v << std::endl;

    vertices.erase(vertices.begin() + 1);
    for (const Vertex& v : vertices)
        std::cout << v << std::endl;
}

int main()
{
    std::vector<Vertex> vertices;
    vertices.reserve(3);

    // By knowing your environment you are able to optimize your code to run faster.
    // This is why it is so important to understand datastructures as well as how the language
    // itself works. 6 copies reduced to 0 copies!

    vertices.emplace_back(1, 2, 3);
    vertices.emplace_back(4, 5, 6);
    vertices.emplace_back(7, 8, 9);

    std::cin.get();
}
