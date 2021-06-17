#include "log.h"
#include <iostream>

void printName(const std::string& name) { LOG("[lvalue] " << name); }

// Since the rvalue is temporary the compiler can safely steal the mem location without worry of some other
// part of the program wanting access to the argument. Hence, it can safely delete upon poping the stack without
// even though it hasn't copied the argument in the first place.
void printName(const std::string&& name) { LOG("[rvalue] " << name); }

int main()
{
    LOG("Hello, World!");

    std::string fname = "Moe";
    std::string pname = "Mark";

    std::string fullName = fname + pname;

    printName(fullName);
    printName(fname + pname);
    std::cin.get();
}
