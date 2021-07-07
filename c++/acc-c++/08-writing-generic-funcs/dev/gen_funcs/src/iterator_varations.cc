// Source file contains example algorithms using all 5 variants of C++ iterator types.

#include <algorithm>

// 1. Input Iterator.
//
// Must support:
//
// ++ (prefix/postfix)
// ==, !=
// unary *

template <class In, class X> In find(In begin, In end, const X& x)
{
    while (begin != end && *begin != x)
        ++begin;
    return begin;
}

template <class In, class X> In find_tr(In begin, In end, const X& x)
{
    if (begin == end || *begin == x)
        return begin;
    begin++;
    return find_tr(begin, end, x);
}

// 2. Output Iterator.
//
// Must support:
//
// ++ (prefix/postfix)
// = (assignment)
// unary *
// increment iterator only once between each assignment (implicit req)

template <class In, class Out> Out copy(In begin, In end, Out dest)
{
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

// 3. Forward Iterator.
//
// Must support:
//
// all operations that Output and Input Iterator supports.
// (does not need to support the increment once restriction)

template <class For, class X> void replace(For beg, For end, const X& x, const X& y)
{
    while (beg != end) {
        if (*beg == x)
            *beg = y;
        ++beg;
    }
}

// 4. Bidirectional Iterator.
//
// Must support:
//
// -- (prefix/postfix)
// all requirements of Forward Iterator

template <class Bi> void reverse(Bi begin, Bi end)
{
    while (begin != end) {
        --end;
        if (begin != end)
            std::swap(*begin++, *end);
    }
}

// 5. Random Access Iterator.
// Must support:
//
// all requirements of Bidirectional
// if p and q are iterators and n is an int, then:
// p + n, p - n, and n + p
// p - q
// p[n] (equivalent to *(p + n))
// p < q, p > q, p <= q, and p >= q

// Inplace search - no recursion.
template <class Ran, class X> bool binary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end) {
        Ran mid = begin + (end - begin) / 2;

        if (x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        else
            return true;
    }

    return false;
}
