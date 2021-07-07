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
    vector<Student_info> students;
    Student_info record;
    string::size_type max_name_len = 0;

    // Read and store all the students data.
    // Invariants:
    //  students contains all the students records read so far.
    //  max_name_len contains the length of the longest name in students.
    while (read(cin, record)) {
        max_name_len = max(max_name_len, record.name.size());
        students.push_back(record);
    }

    // Alphabetize the student records.
    sort(students.begin(), students.end(), compare);

    // Write the names and grades to stdin.
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name << string(max_name_len + 1 - students[i].name.size(), ' ');

        // Compute and write the grade.
        try {
            double fin_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << fin_grade << setprecision(prec);
        } catch (domain_error& e) {
            cout << e.what();
        }
        cout << "\n";
    }
}
