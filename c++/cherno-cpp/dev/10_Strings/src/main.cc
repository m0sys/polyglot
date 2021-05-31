#include <iostream>
#include <string>

#include <stdlib.h>
#include <string.h>

void PrintString(const std::string& string) { std::cout << string << std::endl; }

int main()
{
    const char* name = "Moe";
    char name2[4] = { 'M', 'o', 'e', '\0' };
    std::string name3 = std::string("Moe") + ", hello!";

    PrintString(name);
    PrintString(name2);
    PrintString(name3);

    // String Literals.
    const char name4[8] = "Cherno";
    const wchar_t* name5 = L"Cherno";
    const char16_t* name6 = u"Cherno";
    const char32_t* name7 = U"Cherno";

    std::cout << strlen(name4) << std::endl;
    std::cout << name5 << std::endl;
    std::cout << name6 << std::endl;
    std::cout << name7 << std::endl;

    using namespace std::string_literals;
    std::string name0 = "Cherno"s + ", hello!";
    std::cout << name0 << std::endl;

    const char* example = R"(Line1
    Line2
    Line3
    Line4)";
    std::cout << example << std::endl;

    std::cin.get();
}
