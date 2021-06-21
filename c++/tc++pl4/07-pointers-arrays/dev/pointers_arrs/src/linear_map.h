#pragma once
#include <utility>
#include <vector>

template <class K, class V> class LinearMap {
public:
    V& operator[](const K& k);

    std::pair<K, V>* begin();
    std::pair<K, V>* end();

private:
    std::vector<std::pair<K, V>> elem;
};
