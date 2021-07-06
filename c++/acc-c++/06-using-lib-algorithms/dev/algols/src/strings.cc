#include <algorithm>
#include <cctype>
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

bool is_palindrome(const string& s) { return std::equal(s.begin(), s.end(), s.rbegin()); }

// URL magic.

bool not_url_char(char c)
{
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e) { return find_if(b, e, not_url_char); }

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";

    using const_iterator = string::const_iterator;
    const_iterator i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        if (i != b && i + sep.size() != e) {
            const_iterator beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;

            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }

        i += sep.size();
    }
    return e;
}

vector<string> find_urls(const string& s)
{
    vector<string> ret;
    using const_iterator = string::const_iterator;
    const_iterator b = s.begin(), e = s.end();

    while (b != e) {
        b = url_beg(b, e);

        if (b != e) {
            const_iterator after = url_end(b, e);

            ret.push_back(string(b, after));

            b = after;
        }
    }
    return ret;
}
