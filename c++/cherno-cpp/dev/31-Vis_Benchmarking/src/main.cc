#include "minitrace.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>

struct ProfileResult {
    std::string name;
    long long start, end;
    uint32_t thread_id;
};

struct InstrumentationSession {
    std::string name;
};

class Instrumentor {
private:
    InstrumentationSession* current_session;
    std::ofstream output_stream;
    int profile_count;

public:
    Instrumentor()
        : current_session(nullptr)
        , profile_count()
    {
    }

    void BeginSession(const std::string& name, const std::string& filepath = "results.json")
    {
        output_stream.open(filepath);
        WriteHeader();
        current_session = new InstrumentationSession { name };
    }

    void EndSession()
    {
        WriteFooter();
        output_stream.close();
        delete current_session;
        current_session = nullptr;
        profile_count = 0;
    }

    void WriteProfile(const ProfileResult& result)
    {
        if (profile_count++ > 0)
            output_stream << ",";

        std::string name = result.name;
        std::replace(name.begin(), name.end(), '"', '\'');
        output_stream << "{";
        output_stream << "\"cat\":\"function\",";
        output_stream << "\"dur\":" << (result.end - result.start) << ',';
        output_stream << "\"name\":\"" << name << "\",";
        output_stream << "\"ph\":\"X\",";
        output_stream << "\"pid\":0,";
        output_stream << "\"tid\":" << result.thread_id << ",";
        output_stream << "\"ts\":" << result.start;
        output_stream << "}";

        output_stream.flush();
    }

    void WriteHeader()
    {
        output_stream << "{\"other_data\": {}, \"trace_events\":[";
        output_stream.flush();
    }

    void WriteFooter()
    {
        output_stream << "]}";
        output_stream.flush();
    }

    static Instrumentor& Get()
    {
        static Instrumentor instance;
        return instance;
    }
};

class InstrumentationTimer {
public:
    InstrumentationTimer(const std::string name)
        : name { name }
        , stopped { false }
    {
        start_timeptn = std::chrono::high_resolution_clock::now();
    }

    ~InstrumentationTimer()
    {
        if (!stopped)
            Stop();
    }

    void Stop()
    {
        auto end_timeptn = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_timeptn).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_timeptn).time_since_epoch().count();
        // auto dur = end - start;
        // double ms = dur * 0.001;
        // std::cout << name << ": " << dur << "us (" << ms << "ms)\n";
        uint32_t thread_id = std::hash<std::thread::id> {}(std::this_thread::get_id());
        Instrumentor::Get().WriteProfile({ name, start, end, thread_id });
        stopped = true;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_timeptn;
    std::string name;
    bool stopped;
};

class Timer {

public:
    Timer(const std::string job_name)
        : job_name { job_name }
        , is_stopped { false }
    {
        start_timeptn = std::chrono::high_resolution_clock::now();
    }

    ~Timer() { Stop(); }

    void Stop()
    {
        auto end_timeptn = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_timeptn).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_timeptn).time_since_epoch().count();
        auto dur = end - start;
        double ms = dur * 0.001;
        std::cout << job_name << ": " << dur << "us (" << ms << "ms)\n";
        is_stopped = true;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_timeptn;
    std::string job_name;
    bool is_stopped;
};

#define PROFILING 1
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)
#else
#define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION()
#endif

void func1()
{
    PROFILE_FUNCTION();
    MTR_SCOPE("main", "func1")
    // Timer timer("func1");
    for (int i = 0; i < 10000; i++)
        std::cout << "Hello, World! #" << i << '\n';
}

void func2()
{

    PROFILE_FUNCTION();
    MTR_SCOPE("main", "func2")
    // Timer timer("func2");
    for (int i = 0; i < 10000; i++)
        std::cout << "Hello, World! #" << sqrt(i) << '\n';
}

void run_benchmarks()
{
    PROFILE_FUNCTION();
    func1();
    func2();
}

int main()
{
    // mtr_init("trace.json");

    // Instrumentor::Get().BeginSession("Profile");
    // run_benchmarks();
    // Instrumentor::Get().EndSession();

    // mtr_flush();
    // mtr_shutdown();
    // std::cin.get();

    using namespace std;
    mtr_init("trace.json");

    MTR_META_PROCESS_NAME("minitrace_test");
    MTR_META_THREAD_NAME("main thread");

    MTR_START("background", "long_running", &long_running_thing_1);
    MTR_START("background", "long_running", &long_running_thing_2);

    MTR_BEGIN("main", "outer");
    this_thread::sleep_for(chrono::seconds(1));
    for (int i = 0; i < 3; i++) {
        MTR_BEGIN("main", "inner");
        this_thread::sleep_for(chrono::seconds(1));
        MTR_END("main", "inner");
        this_thread::sleep_for(chrono::seconds(1));
    }
    MTR_STEP("background", "long_running", &long_running_thing_1, "middle step");
    this_thread::sleep_for(chrono::seconds(1));
    MTR_END("main", "outer");

    this_thread::sleep_for(chrono::seconds(1));
    MTR_INSTANT("main", "the end");
    this_thread::sleep_for(chrono::seconds(1));
    MTR_FINISH("background", "long_running", &long_running_thing_1);
    MTR_FINISH("background", "long_running", &long_running_thing_2);

    mtr_flush();
    mtr_shutdown();
    return 0;
}
