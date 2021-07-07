#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;

void word_count(std::istream& is, std::ostream& os)
{
    string s;
    map<string, int> counters;

    while (is >> s)
        ++counters[s];

    for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
        os << it->first << "\t" << it->second << "\n";
    }
}
