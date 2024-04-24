// Write a program to create one dimensional, two dimensional and three dimensional arrays in memory and then
// verify the various address calculation formulae for any arbitrary element of these arrays.
#include <iostream>
using namespace std;

int main()
{
    int oneD[5] = {1, 2, 3, 4, 5};
    cout << "1D: &oneD[0]: " << &oneD[0] << ", &oneD[1]: " << &oneD[1] << ", &oneD[2]: " << &oneD[2] << endl;

    int twoD[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "2D: &twoD[0][0]: " << &twoD[0][0] << ", &twoD[1][0]: " << &twoD[1][0] << ", &twoD[2][0]: " << &twoD[2][0] << endl;

    int threeD[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
    cout << "3D: &threeD[0][0][0]: " << &threeD[0][0][0] << ", &threeD[1][0][0]: " << &threeD[1][0][0] << ", &threeD[1][1][1]: " << &threeD[1][1][1] << endl;

    return 0;
}
