#include <iostream>
using namespace std;
void Sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int binarySearch(int *arr, int target, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // sorting the array
    Sort(arr, n);
    int target;
    cin >> target;
    int index = binarySearch(arr, target, n);
    if (index != -1)
    {
        cout << target << " Found at index: " << index << endl;
    }
    else
        cout << target << " Not found" << endl;
}