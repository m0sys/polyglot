#include "grade.h"
#include "student_info.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    vector<Student_info> did, didnt;

    // Read the student records and partition them.
    Student_info student;
    while (read(cin, student)) {
        if (did_all_hws(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    // Verify that the analysis is useful.
    if (did.empty()) {
        cout << "No student did all the homeworks"
             << "\n";
        return 1;
    }

    if (didnt.empty()) {
        cout << "Every student did all the homeworks"
             << "\n";
        return 1;
    }

    // Do Analyses.
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", avg_analysis, did, didnt);
    write_analysis(cout, "median of homeworks turned in", optimistic_median_analysis, did, didnt);
}
