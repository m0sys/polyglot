#include "linear_map.h"
#include <string>
#include <utility>

template <class K, class V> V& LinearMap<K, V>::operator[](const K& k)
{
    for (auto& x : elem)
        if (k == x.first)
            return x.second;

    elem.push_back({ k, V {} });
    return elem.back().second;
}

template <class K, class V> std::pair<K, V>* LinearMap<K, V>::begin() { return &elem[0]; }

template <class K, class V> std::pair<K, V>* LinearMap<K, V>::end() { return &elem[0] + elem.size(); }

template class LinearMap<std::string, int>;
