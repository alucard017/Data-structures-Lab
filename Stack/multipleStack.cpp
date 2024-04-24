#include <iostream>
using namespace std;

int stack[5];
int top1 = -1, top2 = 5, size = 5;

void pushStack1(int value)
{
    if (top1 + 1 == top2)
    {
        cout << "\nStack 1 is full\n";
        return;
    }
    top1++;
    stack[top1] = value;
}

void pushStack2(int value)
{
    if (top2 - 1 == top1)
    {
        cout << "\nStack 2 is full\n";
        return;
    }
    top2--;
    stack[top2] = value;
}

void popStack1()
{
    if (top1 == -1)
    {
        cout << "Stack 1 is empty\n";
        return;
    }
    cout << "Element popped from Stack 1 is : " << stack[top1] << "\n";
    top1--;
}

void popStack2()
{
    if (top2 == size)
    {
        cout << "Stack 2 is empty\n";
        return;
    }
    cout << "Element popped from Stack 2 is : " << stack[top2] << "\n";
    top2++;
}

void displayStack1()
{
    if (top1 == -1)
    {
        cout << "\nStack 1 is empty\n";
        return;
    }
    cout << "\nStack 1 elements are: ";
    for (int i = top1; i >= 0; i--)
        cout << stack[i] << " ";
    cout << endl;
}

void displayStack2()
{
    if (top2 == size)
    {
        cout << "\nStack 2 is empty\n";
        return;
    }
    cout << "\nStack 2 elements are: ";
    for (int i = top2; i < size; i++)
        cout << stack[i] << " ";
    cout << endl;
}

int main()
{
    int choice, value;
    cout << "1.Push into Stack 1\n";
    cout << "2.Push into Stack 2\n";
    cout << "3.Pop from Stack 1\n";
    cout << "4.Pop from Stack 2\n";
    cout << "5.Display Stack 1\n";
    cout << "6.Display Stack 2\n";
    cout << "7.Exit\n";

    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value to push into Stack 1: ";
            cin >> value;
            pushStack1(value);
            break;
        case 2:
            cout << "Enter the value to push into Stack 2: ";
            cin >> value;
            pushStack2(value);
            break;
        case 3:
            popStack1();
            break;
        case 4:
            popStack2();
            break;
        case 5:
            displayStack1();
            break;
        case 6:
            displayStack2();
            break;
        case 7:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 7);

    return 0;
}
