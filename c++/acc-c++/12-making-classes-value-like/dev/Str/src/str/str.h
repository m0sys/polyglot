#pragma once
#include "../vec/vec.h"
#include <algorithm>
#include <cstring>
#include <iostream>

class Str {
public:
    using size_type = Vec<char>::size_type;
    Str() { }

    Str(size_type n, char c)
        : data(n, c)
    {
    }

    Str(const char* cp) { std::copy(cp, cp + std::strlen(cp), std::back_inserter(data)); }

    template <typename In> Str(In b, In e) { std::copy(b, e, std::back_inserter(data)); }

    Str& operator+=(const Str& s)
    {
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
        return *this;
    }

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }

    friend std::istream& operator>>(std::istream&, Str&);
    size_type size() const { return data.size(); }

private:
    Vec<char> data;
};

std::ostream& operator<<(std::ostream&, const Str&);

Str operator+(const Str&, const Str&);

std::istream& operator>>(std::istream& is, Str& s)
{
    s.data.clear();
    char c;
    while (is.get(c) && isspace(c))
        ; // just testing condition
    if (is) {
        do
            s.data.push_back(c);
        while (is.get(c) && !isspace(c));

        // If we read whitespace - put it back on the stream.
        if (is)
            is.unget();
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

Str operator+(const Str& s1, const Str& s2)
{
    Str r = s1;
    r += s2;
    return r;
}
