#include "algos.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
    vector<string> vect1 { "Hello", "World!", "Let's", "see", "if", "this", "works" };
    vector<string> vect2 { "Let's", "see", "if" };

    auto it = search(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());
    assert(*it == "Let's" && "actual != exepcted");

    vector<string> vect3 { "Should", "not", "work" };
    it = search(vect1.begin(), vect1.end(), vect3.begin(), vect3.end());
    assert(it == vect1.end() && "actual != exepcted");

    std::cout << "Passed!"
              << "\n";
}
