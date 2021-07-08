#pragma once
// grade.h

#include "student_info.h"
#include <iostream>
#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
bool did_all_hws(const Student_info&);
void write_analysis(std::ostream&, const std::string&, double(const std::vector<Student_info>&), const std::vector<Student_info>&, const std::vector<Student_info>&);
double median_analysis(const std::vector<Student_info>&);
double avg_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);
