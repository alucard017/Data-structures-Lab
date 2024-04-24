#include <iostream>
using namespace std;

int linearSearch(int array[], int size, int desired)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == desired)
            return i;
    }

    return -1;
}
int main()
{
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    int desired;
    cin >> desired;
    if (linearSearch(arr, num, desired) != -1)
        cout << "Found" << endl;
    else
        cout << "Number not found" << endl;
    return 0;
}