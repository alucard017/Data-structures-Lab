#include <iostream>
using namespace std;

int queue[5];
int front1 = -1, rear1 = -1, front2 = 5, rear2 = 4, size = 5;

void insertQueue1(int value)
{
    if (rear1 + 1 == front2 || rear1 == size - 1)
    {
        cout << "\nQueue 1 is full\n";
        return;
    }
    else
    {
        if (front1 == -1)
            front1 = 0;
        rear1++;
        queue[rear1] = value;
    }
}

void insertQueue2(int value)
{
    if (rear2 - 1 == front1 || rear2 == -1)
    {
        cout << "\nQueue 2 is full\n";
        return;
    }
    else
    {
        if (front2 == size)
            front2 = size - 1;
        rear2--;
        queue[rear2] = value;
    }
}

void deleteQueue1()
{
    if (front1 == -1 || front1 > rear1)
    {
        cout << "Queue 1 is empty\n";
        return;
    }
    else
    {
        cout << "Element deleted from Queue 1 is : " << queue[front1] << "\n";
        front1++;
    }
}

void deleteQueue2()
{
    if (front2 == size || front2 > rear2)
    {
        cout << "Queue 2 is empty\n";
        return;
    }
    else
    {
        cout << "Element deleted from Queue 2 is : " << queue[front2] << "\n";
        front2++;
    }
}

void displayQueue1()
{
    if (front1 == -1)
    {
        cout << "\nQueue 1 is empty\n";
        return;
    }
    else
    {
        cout << "\nQueue 1 elements are: ";
        for (int i = front1; i <= rear1; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

void displayQueue2()
{
    if (front2 == size)
    {
        cout << "\nQueue 2 is empty\n";
        return;
    }
    else
    {
        cout << "\nQueue 2 elements are: ";
        for (int i = front2; i >= rear2; i--)
            cout << queue[i] << " ";
        cout << endl;
    }
}

int main()
{
    int choice, value;
    cout << "1.Insert into Queue 1\n";
    cout << "2.Insert into Queue 2\n";
    cout << "3.Delete from Queue 1\n";
    cout << "4.Delete from Queue 2\n";
    cout << "5.Display Queue 1\n";
    cout << "6.Display Queue 2\n";
    cout << "7.Exit\n";

    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert into Queue 1: ";
            cin >> value;
            insertQueue1(value);
            break;
        case 2:
            cout << "Enter the value to insert into Queue 2: ";
            cin >> value;
            insertQueue2(value);
            break;
        case 3:
            deleteQueue1();
            break;
        case 4:
            deleteQueue2();
            break;
        case 5:
            displayQueue1();
            break;
        case 6:
            displayQueue2();
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
