#include <iostream>
using namespace std;

int stack[5];
int top = -1, size = 5;

void push(int value)
{
    if (top == size - 1)
    {
        cout << "\nStack is full\n";
        return;
    }
    top++;
    stack[top] = value;
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Element popped from stack is : " << stack[top] << "\n";
    top--;
}

void display()
{
    if (top == -1)
    {
        cout << "\nStack is empty\n";
        return;
    }
    cout << "\nStack elements are: ";
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << endl;
}

int main()
{
    int choice, value;
    cout << "1.Push\n";
    cout << "2.Pop\n";
    cout << "3.Display\n";
    cout << "4.Exit\n";

    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 4);

    return 0;
}
