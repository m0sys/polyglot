#pragma once

// Core header file.
#include "../grade.h"
#include <iostream>
#include <string>
#include <vector>

class Student_info;

class Core {
public:
    Core()
        : midterm { 0 }
        , final { 0 }
    {
    }

    Core(std::istream& is) { read(is); }

    std::string name() const { return n; }
    virtual double grade() const;
    virtual std::istream& read(std::istream&);
    virtual ~Core() { }

    // bool valid() const { return !hws.empty(); }

protected:
    std::istream& read_common(std::istream&);
    virtual Core* clone() const { return new Core(*this); }

protected:
    double midterm, final;
    std::vector<double> hws;

private:
    std::string n;

    friend class Student_info;
};

// bool compare(const Core&, const Core&);
// bool compare_core_ptrs(const Core* cp1, const Core* cp2);
// // std::istream& read(std::istream&, Core&);
// std::istream& read_hws(std::istream&, std::vector<double>&);

bool compare(const Core& x, const Core& y) { return x.name() < y.name(); }

bool compare_core_ptrs(const Core* cp1, const Core* cp2) { return compare(*cp1, *cp2); }

// Read homework grades from an input stream into a `vector`.
std::istream& read_hws(std::istream& is, std::vector<double>& hws)
{
    if (is) {
        // Get rid of previous contents.
        hws.clear();

        double x;
        while (is >> x)
            hws.push_back(x);

        // Clear the stream so that input will work for the next student.
        is.clear();
    }
    return is;
}

double Core::grade() const { return ::grade(midterm, final, hws); }

// Read and store student's name and exam grades.
std::istream& Core::read_common(std::istream& is)
{
    is >> n >> midterm >> final;
    return is;
}

// Read and store the student's name and grades (midterm, final, homeworks).
std::istream& Core::read(std::istream& is)
{
    read_common(is);
    read_hws(is, hws);
    return is;
}
