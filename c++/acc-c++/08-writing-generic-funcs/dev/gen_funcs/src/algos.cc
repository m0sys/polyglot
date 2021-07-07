// Source file contains solutions to chapter 8 exercises.

// Exercise 8.2:
//
// Implement algorithms.

template <class In> bool equal(In begin, In end, In dest)
{
    while (begin != end) {
        if (begin++ != dest++)
            return false;
    }
    return true;
}
