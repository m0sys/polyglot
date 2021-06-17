#include "log.h"
#include <chrono>
#include <iostream>
#include <thread>

struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    Timer() { start = std::chrono::high_resolution_clock::now(); }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        LOG("ELAPSED TIME: " << ms << "ms");
    }
};

void Function()
{
    Timer timer;
    for (int i = 0; i < 100; i++)
        LOG("Hello");
}

int main()
{
    using namespace std::literals::chrono_literals;
    auto start = std::chrono::high_resolution_clock::now();
    Timer timer;
    std::this_thread::sleep_for(1s);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    LOG("ELAPSED TIME: " << duration.count()) << "s";

    Function();
    std::cin.get();
}
