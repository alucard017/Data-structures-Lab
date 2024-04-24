#include <iostream>
using namespace std;

int Parition(int array[], int left, int right)
{
    int pivot = array[left];
    int index = right;
    int temp;

    for (int j = right; j > left; j--)
    {
        if (array[j] > pivot)
        {
            temp = array[j];
            array[j] = array[index];
            array[index] = temp;
            index--;
        }
    }

    array[left] = array[index];
    array[index] = pivot;
    return index;
}

void Quick(int array[], int left, int right)
{
    if (left < right)
    {
        int pivot = Parition(array, left, right);

        Quick(array, left, pivot - 1);
        Quick(array, pivot + 1, right);
    }
}

void Quick_Sort(int array[], int size)
{
    Quick(array, 0, size - 1);
}

void Print_Array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Quick_Sort(arr, n);
    Print_Array(arr, n);
    return 0;
}
