// Source file for Core & related functions.

#include "core.h"
#include "../grade.h"

using std::istream;
using std::vector;

bool compare(const Core& x, const Core& y) { return x.name() < y.name(); }

// Read homework grades from an input stream into a `vector`.
istream& read_hws(istream& is, vector<double>& hws)
{
    if (is) {
        // Get rid of previous contents.
        hws.clear();

        double x;
        while (is >> x)
            hws.push_back(x);

        // Clear the stream so that input will work for the next student.
        is.clear();
    }
    return is;
}

double Core::grade() const { return ::grade(midterm, final, hws); }

// Read and store student's name and exam grades.
istream& Core::read_common(istream& is)
{
    is >> n >> midterm >> final;
    return is;
}

// Read and store the student's name and grades (midterm, final, homeworks).
istream& Core::read(istream& is)
{
    read_common(is);
    read_hws(is, hws);
    return is;
}
