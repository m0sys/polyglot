#pragma once

#include <iostream>
#include <map>
#include <string>

// 15.3.1. Single-Header Organization

namespace Parser {
double expr(bool);
double term(bool);
double prim(bool);
}

namespace Lexer {

enum class Kind : char { name, number, end, plus = '+', minus = '-', mul = '*', div = '/', print = ';', assign = '=', lp = '(', rp = ')' };

struct Token {
    Kind kind;
    std::string string_value;
    double number_value;
};

class Token_stream {
public:
    Token_stream(std::istream& s)
        : ip { &s }
        , owns { false }
        , ct { Kind::end }
    {
    }

    Token_stream(std::istream* p)
        : ip { p }
        , owns { true }
        , ct { Kind::end }
    {
    }

    ~Token_stream() { close(); }
    Token get();      // read and return the next token
    Token& current(); // most recent read token

    void set_input(std::istream& s)
    {
        close();
        ip = &s;
        owns = false;
    }

    void set_input(std::istream* p)
    {
        close();
        ip = p;
        owns = true;
    }

private:
    void close()
    {
        if (owns)
            delete ip;
    }

    std::istream* ip;       // pointer to an input stream
    bool owns;              // does the Token_stream own the istream?
    Token ct { Kind::end }; // current_token
};

extern Token_stream ts;

};

namespace Table {
extern std::map<std::string, double> table;
}

namespace Error {
extern int no_of_errors;
double error(const std::string& s);
}

namespace Driver {
void calculate();
}
