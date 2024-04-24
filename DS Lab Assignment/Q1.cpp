// Write a program to create a one dimensional array at run time using a user defined function with user given
// number of elements into it. Also write separate functions that would allow you to insert and delete elements
// into/from this array at any arbitrary location.

#include <iostream>
using namespace std;

void createArray(int *&arr, int size)
{
    arr = new int[size];
}

void insertElement(int *&arr, int &size, int element, int position)
{
    int *temp = new int[size + 1];
    for (int i = 0; i < position; i++)
    {
        temp[i] = arr[i];
    }
    temp[position] = element;
    for (int i = position + 1; i <= size; i++)
    {
        temp[i] = arr[i - 1];
    }
    delete[] arr;
    arr = temp;
    size++;
}

void deleteElement(int *&arr, int &size, int position)
{
    if (position >= 0 && position < size)
    {
        int *temp = new int[size - 1];
        for (int i = 0; i < position; i++)
        {
            temp[i] = arr[i];
        }
        for (int i = position + 1; i < size; i++)
        {
            temp[i - 1] = arr[i];
        }
        delete[] arr;
        arr = temp;
        size--;
    }
    else
    {
        cout << "Invalid position\n";
    }
}

int main()
{
    int *array;
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    createArray(array, size);

    cout << "Enter " << size << " elements into the array:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    cout << "Array before insertion and deletion:\n";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    int element, position;
    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the position to insert at: ";
    cin >> position;
    insertElement(array, size, element, position);

    cout << "Array after insertion:\n";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Enter the position to delete from: ";
    cin >> position;
    deleteElement(array, size, position);

    cout << "Array after deletion:\n";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
    return 0;
}
