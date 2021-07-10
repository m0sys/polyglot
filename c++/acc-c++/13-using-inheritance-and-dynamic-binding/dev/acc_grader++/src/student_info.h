#pragma once

// Student_info header file.
#include <iostream>
#include <string>
#include <vector>

class Student_info {
public:
    Student_info()
        : midterm { 0 }
        , final { 0 }
    {
    }

    Student_info(std::istream& is) { read(is); }

    double grade() const;
    std::istream& read(std::istream&);
    std::string name() const { return n; }
    bool valid() const { return !hws.empty(); }

private:
    static std::istream& read_hws(std::istream& in, std::vector<double>& hws);

private:
    std::string n;
    double midterm, final;
    std::vector<double> hws;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hws(std::istream&, std::vector<double>&);
