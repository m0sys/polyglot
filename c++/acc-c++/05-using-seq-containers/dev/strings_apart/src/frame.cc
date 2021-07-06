#include <algorithm>
#include <string>
#include <vector>

using std::max;
using std::string;
using std::vector;

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());

    return maxlen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    // Top border.
    ret.push_back(border);

    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }
    // Bot border.
    ret.push_back(border);
    return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bot)
{
    vector<string> ret = top;
    ret.insert(ret.end(), bot.begin(), bot.end());

    return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    using vec_sz = vector<string>::size_type;
    using str_sz = string::size_type;
    vector<string> ret;

    str_sz width1 = width(left) + 1; // add one for space between pictures
    vec_sz i = 0, j = 0;

    while (i != left.size() || j != right.size()) {
        string s;

        if (i != left.size())
            s = left[i++];

        s += string(width1 - s.size(), ' ');

        if (j != right.size())
            s += right[j++];

        ret.push_back(s);
    }

    return ret;
}
