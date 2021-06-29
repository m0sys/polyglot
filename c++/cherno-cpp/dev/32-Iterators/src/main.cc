#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    std::cout << "Hello, World!\n";

    std::vector<int> values = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < (int)values.size(); i++)
        std::cout << values[i] << "\n";

    for (int val : values)
        std::cout << val << "\n";

    for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
        std::cout << *it << "\n";

    using ScoreMap = std::unordered_map<std::string, int>;
    ScoreMap map;
    map["Moe"] = 5;
    map["C++"] = 2;

    for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << "\n";
    }

    for (auto kv : map) {
        std::cout << "Key: " << kv.first << ", Value: " << kv.second << "\n";
    }

    for (auto [key, val] : map) {
        std::cout << key << " = " << val << "\n";
    }

    std::cin.get();
}
