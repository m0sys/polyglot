#pragma once
// grade.h

#include "students/core.h"
#include <iostream>
#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
bool fgrade(const Core&);
std::vector<Core> extract_fails(std::vector<Core>&);
bool did_all_hws(const Core&);
void write_analysis(std::ostream&, const std::string&, double(const std::vector<Core>&), const std::vector<Core>&, const std::vector<Core>&);
double median_analysis(const std::vector<Core>&);
double avg_analysis(const std::vector<Core>&);
double optimistic_median_analysis(const std::vector<Core>&);
