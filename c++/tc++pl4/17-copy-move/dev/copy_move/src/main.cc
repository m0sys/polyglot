#include <iostream>
#include <list>
#include <utility>
#include <vector>

// 17.1. Introduction

template <typename Sometype> class X {
    X(Sometype);            // "ordinary constructor": create an object.
    X();                    // default constructor
    X(const X&);            // copy constructor
    X(X&&);                 // move constructor
    X& operator=(const X&); // copy assignment: clean up target and copy
    X& operator=(X&&);      // move assignment: clean up target and move
    ~X();
};

// 17.2.5. virtual Destructors

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape();
};

class Circle {
public:
    void draw();
    ~Circle(); // overrides ~Shape()
};

void user(Shape* p)
{
    // Expression of polymorphic behaviour.

    p->draw(); // invoke the appropriate draw()
    // NOTE: if destructor was not virtual then only the base class destructor would be called
    //        potentially leading to a mem leak.

    delete p; // invoke the appropriate destructor
}

// 17.3.1. Initialization Without Constructors

struct Work {
    std::string author;
    std::string name;
    int year;
};

void beethoven_like_you_never_hear()
{
    Work s9 { "Beethoven", "Symphony No. 9 in D minor, Op. 125; Choral", 1824 }; // memwise init
    std::cout << s9.author << '\t';
    std::cout << s9.name << '\t';
    std::cout << s9.year << '\t';
    std::cout << '\n';

    Work curr_playing { s9 }; // copy init
    Work none {};             // default init
}

// 17.3.4. Initializer-List Constructors

void init_containers()
{
    using namespace std;
    vector<double> v = { 1, 2, 3.456, 99.99 };
    list<pair<string, string>> langs = { { "Nygaard", "Simula" }, { "Richards", "BCPL" }, { "Ritchie", "C" } };

    for (const auto& x : v)
        cout << x << " ";

    for (const auto& x : langs)
        cout << "Lang Designer: " << x.first << ", Language: " << x.second << endl;
}

void func_init(std::initializer_list<int> lst)
{
    for (const auto& x : lst)
        std::cout << x << " ";
    std::cout << '\n';
}

struct X2 {
    X2(std::initializer_list<int>) { std::cout << "Called Init List Constructor!" << '\n'; }
    X2() { std::cout << "Called Default Constructor!" << '\n'; }
    X2(int) { std::cout << "Called Arg Constructor!" << '\n'; }
};

void precedence_construction()
{
    X2 x {};     // default constructor
    X2 x1 { 1 }; // initializer_list constructor
    X2 x3(1);    // arg constructor
}

// 17.5.1.3. The Meaning of Copy - as the Meaning of Life (Hah.)

// An example of copy-on-write technique.

struct Representation {
};

struct Descriptor {
};

class Image {
public:
    Image(const Image& a); // copy constructor
    void write_block(Descriptor);

private:
    Representation* clone(); // copy *rep
    Representation* rep;
    bool shared;
};

void Image::write_block(Descriptor d)
{
    if (shared) {
        rep = clone();  // make a copy of *rep
        shared = false; // no more sharing
    }
}

int main()
{
    init_containers();
    func_init({ 1, 2, 3, 4, 100, 200, 400 });
    precedence_construction();
}
