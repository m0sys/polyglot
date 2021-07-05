#include <iostream>
#include <string>

bool on_boarder(int rows, int cols, int r, int c) { return r == 0 || r == rows - 1 || c == 0 || c == cols - 1; }
bool done_with_padding(int r, int c, int pad) { return r == pad + 1 && c == pad + 1; }

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";

    // Number of blanks surrounding greeting.
    int pad;

    cout << "Please enter the amount of padding: ";
    cin >> pad;

    // Number of rows and cols to write.
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    // Seperate input from the output.
    cout << "\n";

    // Invariant: we have written r rows so far.
    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;

        // Invariant: we have written c chars so far in the current row.
        while (c != cols) {
            if (done_with_padding(r, c, pad)) {
                cout << greeting;
                c += greeting.size();
            } else {
                if (on_boarder(rows, cols, r, c))
                    cout << "*";
                else // apply padding
                    cout << " ";
                ++c;
            }
        }
        cout << "\n";
    }
}
