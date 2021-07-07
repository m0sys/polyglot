// Source file containing the functionality to generate sentences based on structured rules.

#include "strings.h"
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

using std::logic_error;
using std::map;
using std::string;
using std::vector;

using Rule = vector<string>;
using Rule_coll = vector<Rule>;
using Grammer = map<string, Rule_coll>;

// Read a grammer from a given input stream.
Grammer read_grammer(std::istream& is)
{
    Grammer ret;
    string line;

    while (getline(is, line)) {
        vector<string> entry = split(line);

        if (!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    return ret;
}

// Return a random int in the range [0, n).
int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw std::domain_error("Argument to nrand is out of range.");

    const int bucket_size = RAND_MAX / n;
    int r;
    do
        r = rand() / bucket_size;
    while (r >= n);
    return r;
}

bool is_bracketed(const string& s) { return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>'; }

void gen_aux(const Grammer& g, const string& word, vector<string>& ret)
{
    if (!is_bracketed(word)) {
        ret.push_back(word);
    } else {
        // Locate rule corresponding to word.
        Grammer::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");

        const Rule_coll& c = it->second;
        const Rule& r = c[nrand(c.size())];

        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

vector<string> gen_sentence(const Grammer& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

void run_sentence_generator(std::istream& is, std::ostream& os)
{
    vector<string> sentence = gen_sentence(read_grammer(is));

    vector<string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
        os << *it;
        ++it;
    }

    while (it != sentence.end()) {
        os << " " << *it;
        ++it;
    }

    os << "\n";
}
