// Source file for Student_info & related functions.

#include "student_info.h"
#include "grade.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y) { return x.name() < y.name(); }

// Read and store the student's name and grades (midterm, final, homeworks).
istream& Student_info::read(istream& is)
{
    is >> n >> midterm >> final;

    read_hws(is, hws);
    grade();
    return is;
}

// Read homework grades from an input stream into a `vector`.
istream& Student_info::read_hws(istream& in, vector<double>& hws)
{
    if (in) {
        // Get rid of previous contents.
        hws.clear();

        double x;
        while (in >> x)
            hws.push_back(x);

        // Clear the stream so that input will work for the next student.
        in.clear();
    }
    return in;
}

double Student_info::grade() const
{
    static bool precomputed = false;
    static double g = 0;

    if (precomputed) {
        return g;
    }

    g = ::grade(midterm, final, hws);
    return g;
}
