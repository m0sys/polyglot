#include "mem/handle.h"
#include "students/core.h"
#include "students/grad.h"
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
    // Read student records.
    vector<Handle<Core>> students;
    Handle<Core> record;
    char ch;
    string::size_type max_name_len = 0;

    while (cin >> ch) {
        if (ch == 'U')
            record = new Core;
        else
            record = new Grad;
        record->read(cin);
        max_name_len = max(max_name_len, record->name().size());
        students.push_back(record);
    }

    // Sort records alphabetically by name.
    sort(students.begin(), students.end(), compare_core_ptrs);

    // Write the names and grades.
    for (vector<Handle<Core>>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i]->name() << string(max_name_len + 1 - students[1]->name().size(), ' ');

        try {
            double final_grade = students[i]->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec) << "\n";
        } catch (domain_error& err) {
            cout << err.what() << "\n";
        }
    }
}
