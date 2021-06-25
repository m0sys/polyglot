#include "log.h"
#include <chrono>
#include <iostream>
#include <memory>

class Timer {

public:
    Timer() { start_timeptn = std::chrono::high_resolution_clock::now(); }

    ~Timer() { Stop(); }

    void Stop()
    {
        auto end_timeptn = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_timeptn).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_timeptn).time_since_epoch().count();
        auto dur = end - start;
        double ms = dur * 0.001;
        std::cout << "Time elapsed: " << dur << "us (" << ms << "ms)\n";
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_timeptn;
};

struct Vector2 {
    float x, y;
};

int main()
{
    LOG("Hello, World!");
    int value = 0;

    {
        Timer timer;
        for (int i; i < 1000000; i++)
            value += 2;
    }

    {
        std::cout << "Make Shared\n";
        std::array<std::shared_ptr<Vector2>, 100000> shared_ptrs;
        Timer timer;
        for (int i = 0; i < (int)shared_ptrs.size(); i++)
            shared_ptrs[i] = std::make_shared<Vector2>();
    }

    {
        std::cout << "\nMake Unique\n";
        std::array<std::unique_ptr<Vector2>, 100000> unique_ptrs;
        Timer timer;
        for (int i = 0; i < (int)unique_ptrs.size(); i++)
            unique_ptrs[i] = std::make_unique<Vector2>();
    }

    {
        std::cout << "\nMake Raw\n";
        std::array<Vector2*, 100000> shared_ptrs2;
        Timer timer;
        for (int i = 0; i < (int)shared_ptrs2.size(); i++)
            shared_ptrs2[i] = new Vector2;
    }

    std::cout << value << '\n';
    std::cin.get();
}
