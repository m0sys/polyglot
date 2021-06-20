#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// 5.3.1. Tasks and threads

void f() { std::cout << "Hello "; }

struct F {
    void operator()() { std::cout << "Parallel World!\n"; }
};

void user()
{
    using namespace std;
    thread t1 { f };
    thread t2 { F() };

    t1.join(); // wait for t1
    t2.join(); // wait for t2
}

// 5.3.4. Sharing Data

std::mutex m1;
std::mutex m2;
std::mutex m3;

void f2()
{
    using namespace std;
    unique_lock<mutex> lck1 { m1, defer_lock };
    unique_lock<mutex> lck2 { m2, defer_lock };
    unique_lock<mutex> lck3 { m3, defer_lock };
    lock(lck1, lck2, lck3);
    std::cout << "Aquired all locks!\n";
}

void user2()
{
    using namespace std;

    // vector<thread> thrds;
    // for (int i = 0; i < 10; i++) {
    //     // Since we are running the same job this can be thought of as parallelism
    //     // instead of concurrent.
    //     thread worker { f2 };
    //     thrds.push_back(worker);
    // }

    // for (int i = 0; i < 10; i++) {
    //     thrds[i].join();
    // }

    thread worker1 { f2 };
    thread worker2 { f2 };
    thread worker3 { f2 };

    worker1.join();
    worker2.join();
    worker3.join();
}

int main()
{
    std::thread main_worker { user2 };
    main_worker.join();
    std::cin.get();
}
