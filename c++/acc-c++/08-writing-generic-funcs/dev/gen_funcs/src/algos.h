#pragma once
// Searches the range [first1, last1) for the first occurence of the sequence defined
// by [first2, last2).
template <class For> For search(For first1, For last1, For first2, For last2)
{
    // Find the beginning of [first2, last2).
    while (first1 != last1 && *first1 != *first2)
        ++first1;

    if (first1 == last1)
        return last1;

    // Then first1 == first2.

    For p = first1;
    For q = first2;

    while (first1 != last1 && q != last2 && *first1 == *q) {
        ++first1;
        ++q;
    }
    if (q == last2) // got through the whole sequence
        return p;

    if (first1 == last1)
        return last1;

    // Search the remaining of [first1, last1).
    return search(first1, last1, first2, last2);
}
