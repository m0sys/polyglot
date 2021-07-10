#include "grad.h"
#include <algorithm>
#include <iostream>

using std::istream;

istream& Grad::read(istream& is)
{
    read_common(is);
    is >> thesis;
    read_hws(is, hws);
    return is;
}

double Grad::grade() const { return std::min(Core::grade(), thesis); }
