#include "strings.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
    string s;

    while (std::getline(std::cin, s)) {
	vector<string> v = split(s);
	for (vector<string>::size_type i = 0; i != v.size(); ++i)
	    std::cout << v[i] << "\n";
    }
}
