#include "xref.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

// Find all the lines that refer to each word in the input.
map<string, vector<int>> xref(std::istream& is, vector<string> find_words(const string&))
{
    string line;
    int line_num = 0;
    map<string, vector<int>> ret;

    while (getline(is, line)) {
        ++line_num;

        vector<string> words = find_words(line);

        for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
            ret[*it].push_back(line_num);
    }
    return ret;
}

void print_cross_refs(const map<string, vector<int>>& refs, std::ostream& os)
{
    for (map<string, vector<int>>::const_iterator it = refs.begin(); it != refs.end(); ++it) {
        os << it->first << " occurs on line(s): ";
        vector<int>::const_iterator line_it = it->second.begin();
        os << *line_it;
        ++line_it;
        while (line_it != it->second.end()) {
            os << ", " << *line_it;
            ++line_it;
        }
        os << "\n";
    }
}
