#include <iostream>

// NOTE: this also solves the problem of having to have a fixed size for the col dim.
void display2d(const int* arr, int ni, int nj)
{
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            std::cout << arr[i + j * nj] << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    std::cout << "Hello, World!\n";

    // Array of pointers that will each point to an array of ints.
    int** a2d = new int*[50];
    for (int i = 0; i < 50; i++)
        a2d[i] = new int[50];

    for (int i = 0; i < 50; i++)
        delete[] a2d[i];
    delete[] a2d;

    // NOTE: For every new there should be a delete[].

    // Array of pointers that will each point to an array of pointers that will each point to an array of ints.
    // NOTE: This is very unefficient since all the memory is fragmented.
    //       Instead it would be better to have a datastructure that represents 50*50*50 ints in a single 1D array.
    int*** a3d = new int**[50];
    for (int i = 0; i < 50; i++) {
        a3d[i] = new int*[50];
        for (int j = 0; j < 50; j++) {
            a3d[i][j] = new int[50];
        }
    }

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++)
            for (int k = 0; k < 50; k++)
                a3d[i][j][k] = 0;
    }

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++)
            delete[] a3d[i][j];
        delete[] a3d[i];
    }
    delete[] a3d;

    // Better solution.
    int* arr = new int[5 * 5];
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++)
            arr[x + y * 5] = 2;
    }

    display2d(arr, 5, 5);

    std::cin.get();
}
