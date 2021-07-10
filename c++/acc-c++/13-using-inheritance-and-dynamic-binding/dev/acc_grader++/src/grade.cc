// Source file for grade related functions.

#include "grade.h"
#include "average.h"
#include "median.h"
#include "students/core.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

using std::back_inserter;
using std::domain_error;
using std::list;
using std::ostream;
using std::remove_copy;
using std::remove_copy_if;
using std::remove_if;
using std::string;
using std::transform;
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

// Predicate to determine whether a student failed.
bool fgrade(const Core& s) { return s.grade() < 60; }

// Time Complexity: O(N^2).
vector<Core> extract_fails(vector<Core>& students)
{
    vector<Core> fails;
    vector<Core>::iterator iter = students.begin();

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
list<Core> extract_fails_fast(list<Core>& students)
{
    list<Core> fails;
    list<Core>::iterator iter = students.begin();

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

// 6.3 - using algorithm to extract fails.

// Predicate to determine whether a student passed.
bool pgrade(const Core& s) { return !fgrade(s); }

vector<Core> extract_fails_algo(vector<Core>& students)
{
    vector<Core> fails;
    remove_copy_if(students.begin(), students.end(), back_inserter(fails), pgrade);

    students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
    return fails;
}

vector<Core> extract_fails_algo_fast(vector<Core>& students)
{
    vector<Core>::iterator iter = std::stable_partition(students.begin(), students.end(), pgrade);
    vector<Core> fails(iter, students.end());
    students.erase(iter, students.end());
    return fails;
}

// 6.2.1 - Working with student records.

// FIXME: incorporate functions into Core.

/*
bool did_all_hws(const Core& s) { return ((find(s.hws.begin(), s.hws.end(), 0)) == s.hws.end()); }

double median_grade(const Core& s)
{
    try {
        return s.grade();
    } catch (domain_error&) {
        return grade(s.midterm, s.final, 0);
    }
}

double avg_grade(const Core& s) { return grade(s.midterm, s.final, average(s.hws)); }

// Median of the nonzero elements of s.hws, or 0 if no such elem exist.
double optimistic_median_grade(const Core& s)
{
    vector<double> nonzero;

    remove_copy(s.hws.begin(), s.hws.end(), back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

// Higher order function for doing statistical analysis on student grades.
double stats_analysis(const vector<Core>& students, double grade_func(const Core&))
{

    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), grade_func);
    return median(grades);
}

double median_analysis(const vector<Core>& students) { return stats_analysis(students, median_grade); }

double avg_analysis(const vector<Core>& students) { return stats_analysis(students, avg_grade); }

double optimistic_median_analysis(const vector<Core>& students) { return stats_analysis(students, optimistic_median_grade); }

void write_analysis(ostream& out, const string& name, double analysis(const vector<Core>&), const vector<Core>& did, const vector<Core>& didnt) { out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << "\n"; }
*/
