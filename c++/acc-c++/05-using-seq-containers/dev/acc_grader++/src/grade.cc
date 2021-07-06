// Source file for grade related functions.

#include "grade.h"
#include "median.h"
#include "student_info.h"
#include <list>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::list;
using std::vector;

// Compute the student's overall grade from midterm, final, and stats(homeworks) grades.
double grade(double midterm, double fin_grade, double homeworks) { return 0.2 * midterm + 0.4 * fin_grade + 0.4 * homeworks; }

// Compute a student's overall grade from midterm, final, and vect of homework grades.
double grade(double midterm, double fin_grade, const std::vector<double>& hws)
{
    if (hws.size() == 0)
        throw domain_error("student has done no homework");

    return grade(midterm, fin_grade, median(hws));
}

double grade(const Student_info& s) { return grade(s.midterm, s.final, s.hws); }

// Predicate to determine whether a student failed.
bool fgrade(const Student_info& s) { return grade(s) < 60; }

// Time Complexity: O(N^2).
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fails;
    vector<Student_info>::iterator iter = students.begin();

    // Invariant: elems [0, i) of students represent passing grades.
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fails.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fails;
}

// Time Complexity: O(N).
list<Student_info> extract_fails_fast(list<Student_info>& students)
{
    list<Student_info> fails;
    list<Student_info>::iterator iter = students.begin();

    // Invariant: elems [0, i) of students represent passing grades.
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fails.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fails;
}
