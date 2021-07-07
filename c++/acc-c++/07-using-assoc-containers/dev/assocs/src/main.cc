#include "sentence_generator.h"
#include "wc.h"
#include "xref.h"
#include <iostream>

int main()
{
    // word_count(std::cin, std::cout);
    // auto refs = xref(std::cin);
    // print_cross_refs(refs, std::cout);

    run_sentence_generator(std::cin, std::cout);
}
