#include <cctype> // isspace
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> split(const string& s)
{
    vector<string> ret;
    using str_sz = string::size_type;
    str_sz i = 0;

    while (i != s.size()) {
        // Ignore leading blanks.
        while (i != s.size() && isspace(s[i]))
            ++i;

        // Find end of next word.
        str_sz j = i;
        while (j != s.size() && !isspace(s[j]))
            j++;

        if (i != j) {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}
