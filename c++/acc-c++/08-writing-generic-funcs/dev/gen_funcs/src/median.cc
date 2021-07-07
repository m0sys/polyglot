// Source file for the median functions.

#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;

template <typename T>
T median(vector<T> vec)
{
    using vec_sz = typename vector<T>::size_type;

    vec_sz size = vec.size();
    if (size == 0)
	throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
