// 15.3.1. Single-Header Organization

#include "dc.h"

// placeholder.
Lexer::Token Lexer::Token_stream::get() { return Token { Kind::end }; }

// Lexer::Token& Lexer::Token_stream::current() { /* .. */ }

// Same idea for parser.cpp, etc... - each in its own .cc file.
