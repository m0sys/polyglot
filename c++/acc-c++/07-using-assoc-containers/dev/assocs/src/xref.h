#pragma once

#include "strings.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<std::string, std::vector<int>> xref(std::istream& is, std::vector<std::string> find_words(const std::string&) = split);

void print_cross_refs(const std::map<std::string, std::vector<int>>& refs, std::ostream& os);
