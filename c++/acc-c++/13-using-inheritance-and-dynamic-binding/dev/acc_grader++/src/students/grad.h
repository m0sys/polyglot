#pragma once

#include "core.h"

class Grad : public Core {
public:
    Grad()
        : thesis { 0 }
    {
    }

    Grad(std::istream& is) { read(is); }
    double grade() const;
    std::istream& read(std::istream&);

protected:
    virtual Grad* clone() const { return new Grad(*this); }

private:
    double thesis;
};

std::istream& Grad::read(std::istream& is)
{
    read_common(is);
    is >> thesis;
    read_hws(is, hws);
    return is;
}

double Grad::grade() const { return std::min(Core::grade(), thesis); }
