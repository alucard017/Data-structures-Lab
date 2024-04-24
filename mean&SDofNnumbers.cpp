#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int n;
    double sum = 0, mean = 0, variance = 0, stdDeviation = 0;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<double> numbers(n);

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        sum += numbers[i];
    }

    mean = sum / n;

    for (int i = 0; i < n; i++)
    {
        variance += pow(numbers[i] - mean, 2);
    }

    variance /= n;
    stdDeviation = sqrt(variance);

    cout << "Mean: " << mean << endl;
    cout << "Variance: " << variance << endl;
    cout << "Standard Deviation: " << stdDeviation << endl;

    return 0;
}
