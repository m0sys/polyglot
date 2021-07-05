#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::setprecision;
    using std::sort;
    using std::streamsize;
    using std::string;
    using std::vector;

    // Ask for and student's first name.
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!"
         << "\n";

    // Ask for and read midterm and final grades.
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, fin_grad;
    cin >> midterm >> fin_grad;

    // Ask for the homework grades.
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";

    // The number and sum of grades read so far.

    double hw_grad;
    vector<double> hws;

    // Invariant: hws contains all the homework grades read so far.
    while (cin >> hw_grad) {
        hws.push_back(hw_grad);
    }
    using vec_sz = vector<double>::size_type;
    vec_sz size = hws.size();

    if (size == 0) {
        cout << "\n"
             << "You must enter your grades. "
                "Please try again."
             << "\n";
        return 1;
    }

    // Calculate the median.
    sort(hws.begin(), hws.end());
    vec_sz mid = size / 2;
    double median = size % 2 == 0 ? (hws[mid] + hws[mid - 1]) / 2 : hws[mid];

    // Write the result.
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3) << 0.2 * midterm + 0.4 * fin_grad * 0.4 * median << setprecision(prec) << "\n";
}
