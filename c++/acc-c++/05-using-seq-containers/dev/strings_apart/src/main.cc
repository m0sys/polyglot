#include "frame.h"
#include "strings.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

void print_picture(const vector<string> v)
{
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
	std::cout << v[i] << "\n";
}

// Exercise 5.0.
void test_frame()
{
    string s;

    while (std::getline(std::cin, s)) {
	vector<string> v = split(s);
	vector<string> framed = frame(v);
	print_picture(framed);
    }
}

void test_vcat()
{
    string s = "This is a test!";
    string s2 = "This is a feast!";

    vector<string> v = split(s);
    v = frame(v);

    vector<string> v2 = split(s2);
    v2 = frame(v2);

    vector<string> cat = vcat(v, v2);
    print_picture(cat);
}

void test_hcat()
{
    string s = "This is a test!";
    string s2 = "This is a feast!";

    vector<string> v = split(s);
    v = frame(v);

    vector<string> v2 = split(s2);
    v2 = frame(v2);

    vector<string> cat = hcat(v, v2);
    print_picture(cat);
}

void test_split()
{
    string s;

    while (std::getline(std::cin, s)) {
	vector<string> v = split(s);
	print_picture(v);
    }
}

int main()
{
    test_vcat();
    std::cout << "\n";
    test_hcat();
}
