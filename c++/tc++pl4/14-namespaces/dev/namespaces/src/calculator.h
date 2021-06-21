namespace Parser {
double prim(bool);
double term(bool);
double expr(bool);
}

namespace Lexer {
enum class Kind : char;
class Token;
class Token_stream;
}
