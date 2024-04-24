// WAP to add and subtract following polynomials 5x^2 – 3xy + y, 2x^2 – y^2 + 5xy – x + y using array.

#include <iostream>
using namespace std;

const int maxSize = 3;
int poly1[maxSize + 1] = {0};
int poly2[maxSize + 1] = {0};

void initializePolynomials()
{
    poly1[2] = 5;
    poly1[1] = -3;
    poly1[0] = 1;

    poly2[2] = 2;
    poly2[1] = 5;
    poly2[0] = 1;
    poly2[4] = -1;
    poly2[5] = 1;
}

void addPolynomials()
{
    int sum[maxSize + 1] = {0};
    for (int i = 0; i <= maxSize; i++)
    {
        sum[i] = poly1[i] + poly2[i];
    }
    cout << "Sum of the polynomials: ";
    for (int i = maxSize; i >= 0; i--)
    {
        if (sum[i] != 0)
        {
            cout << sum[i] << "x^" << i << " ";
        }
    }
    cout << endl;
}

void subtractPolynomials()
{
    int diff[maxSize + 1] = {0};
    for (int i = 0; i <= maxSize; i++)
    {
        diff[i] = poly1[i] - poly2[i];
    }
    cout << "Difference of the polynomials: ";
    for (int i = maxSize; i >= 0; i--)
    {
        if (diff[i] != 0)
        {
            cout << diff[i] << "x^" << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    initializePolynomials();
    addPolynomials();
    subtractPolynomials();
    return 0;
}
