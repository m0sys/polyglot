#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

bool isnotspace(char c) { return !isspace(c); }

vector<string> split(const string& str)
{
    using const_iterator = string::const_iterator;
    vector<string> ret;

    const_iterator i = str.begin();
    while (i != str.end()) {
        i = find_if(i, str.end(), isnotspace);

        const_iterator j = find_if(i, str.end(), isspace);

        if (i != str.end())
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}
