#include <iostream>
#include <algorithm>
using namespace std;

void bucketSort(float arr[], int n)
{
    const int size = 10;
    float buckets[size][n];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < n; j++)
        {
            buckets[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int index = size * arr[i];
        buckets[index][i] = arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        sort(buckets[i], buckets[i] + n);
    }

    int index = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (buckets[i][j] != 0)
            {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

int main()
{
    float arr[] = {0.23, 0.67, 0.45, 0.89, 0.12, 0.78, 0.34};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bucketSort(arr, n);

    cout << "Array after sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
