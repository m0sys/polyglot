#include <iostream>
#include <string>

void ask_name()
{
    std::cout << "Please Enter your first name: ";

    // Read the name from stdin.
    std::string name;
    std::cin >> name;

    std::cout << "Hello, " << name << "!"
              << "\n";
}

void ask_name_framed()
{
    using string = std::string;

    std::cout << "Please Enter your first name: ";

    // Read the name from stdin.
    string name;
    std::cin >> name;

    // Build the message that we intent to write.
    const string greeting = "Hello, " + name + "!";

    // Build the second and fourth lines of the output.
    const string spaces(greeting.size(), ' ');
    const string second = "* " + spaces + " *";

    // Build the first and fifth lines of the output.
    const string first(second.size(), '*');

    // Write to stdout.
    std::cout << "\n"
              << first << "\n"
              << second << "\n"
              << "* " << greeting << " *"
              << "\n"
              << second << "\n"
              << first << "\n";
}

void ask_names()
{
    std::cout << "What is your name? ";

    std::string name;
    std::cin >> name;

    std::cout << "Hello, " << name << "\n"
              << "And what is yours? ";

    std::cin >> name;

    std::cout << "Hello, " << name << "; nice to meet you too!"
              << "\n";
}

int main()
{
    ask_names();
    std::cin.get();
}
