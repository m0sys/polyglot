#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

// 4.3.2. Input

void hello()
{
    using namespace std;
    cout << "Please enter your name\n";
    string str;
    cin >> str;
    cout << "Hello, " << str << "!\n";
}

void hello_line()
{
    using namespace std;
    cout << "Please enter your name\n";
    string str;
    getline(cin, str);
    cout << "Hello, " << str << "!\n";
}

// 4.3.3. I/O of User-Defined Types
struct Entry {
    std::string name;
    int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e) { return os << "{\"" << e.name << "\"," << e.number << "}"; }

std::istream& operator>>(std::istream& is, Entry& e)
// read {"name", number} pair. Note: formatted with {"", and }
{
    char c, c2;
    if (is >> c && c == '{' && is >> c2 && c2 == '"') {
        std::string name;
        while (is.get(c) && c != '"')
            name += c;
        if (is >> c && c == ',') {
            int number = 0;
            if (is >> number >> c && c == '}') {
                e = { name, number };
                return is;
            }
        }
    }

    // std::cout.setf(std::ios_base::failbit);
    is.setstate(std::ios::failbit); // register the failure in the stream
    return is;
}

void hello_entry()
{
    using namespace std;
    for (Entry ee; cin >> ee;)
        cout << ee << '\n';
}

// 4.4.1. Vector

void print_book(const std::vector<Entry>& book)
{
    for (const auto& x : book)
        std::cout << x << '\n';
}

void input()
{
    using namespace std;

    vector<Entry> phone_book = { { "David Hume", 123456 }, { "Karl Popper", 234567 }, { "Bertrand Arthur William Russell", 345678 } };

    for (Entry e; cin >> e;)
        phone_book.push_back(e);

    print_book(phone_book);
}

// 4.4.2. List

int get_number(const std::string& s, const std::list<Entry>& book)
{
    for (const auto& x : book)
        if (x.name == s)
            return x.number;
    return 0;
}

int get_number2(const std::string& s, const std::list<Entry>& book)
{
    for (auto p = book.begin(); p != book.end(); ++p) {
        if (p->name == s)
            return p->number;
    }
    return 0;
}

// 4.4.3. Map

int get_number(const std::string& s, const std::map<std::string, int>& book)
{
    // NOTE: map is red-black tree (i.e. a balanced binary tree).
    return book.at(s);
}

// 4.4.4. Unordered Map

int get_number(const std::string& s, const std::unordered_map<std::string, int>& book)
{
    // NOTE: map is red-black tree (i.e. a balanced binary tree).
    return book.at(s);
}

// 4.5. Algorithms

bool operator<(const Entry& a, const Entry& b) { return a.name < b.name; }

void fun(std::vector<Entry>& vec, std::list<Entry> lst)
{
    using namespace std;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), lst.begin());
}

std::list<Entry> fun2(std::vector<Entry>& vec)
{
    using namespace std;
    list<Entry> res;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(res));
    return res;
}

std::vector<std::string::iterator> find_all(std::string& s, char c)
{
    using namespace std;
    vector<string::iterator> res;
    for (auto p = s.begin(); p != s.end(); ++p)
        if (*p == c)
            res.push_back(p);

    return res;
}

void test_find_all()
{
    using namespace std;
    string m { "Mary had a little lamb" };
    for (auto p : find_all(m, 'a'))
        if (*p != 'a')
            cerr << "a bug!\n";
}

// Magic don't work - yet.
// template <typename T> using Iterator<T> = typename T::iterator;
// template <typename C, typename V>
// vector<Iterator<C>>

int main()
{
    input();
    std::cin.get();
}
