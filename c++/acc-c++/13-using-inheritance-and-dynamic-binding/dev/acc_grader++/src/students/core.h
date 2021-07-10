#pragma once

// Core header file.
#include <iostream>
#include <string>
#include <vector>

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

    bool valid() const { return !hws.empty(); }

protected:
    std::istream& read_common(std::istream&);

protected:
    double midterm, final;
    std::vector<double> hws;

private:
    std::string n;
};

bool compare(const Core&, const Core&);
std::istream& read(std::istream&, Core&);
std::istream& read_hws(std::istream&, std::vector<double>&);
