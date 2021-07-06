// Source file for grade related functions.

#include "grade.h"
#include "median.h"
#include "student_info.h"
#include <stdexcept>
#include <vector>

using std::domain_error;
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
