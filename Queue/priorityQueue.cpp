#include <iostream>
using namespace std;

const int maxQueueSize = 100;
const int maxPriority = 10;

struct Element
{
    int data;
    int priority;
};

void enqueue(Element queue[][maxPriority], int front[], int rear[], int data, int priority)
{
    if (rear[priority] == maxQueueSize - 1)
    {
        cout << "Queue Overflow\n";
        return;
    }
    rear[priority]++;
    queue[rear[priority]][priority].data = data;
    queue[rear[priority]][priority].priority = priority;
    if (front[priority] == -1)
    {
        front[priority] = rear[priority];
    }
}

void dequeue(Element queue[][maxPriority], int front[], int rear[])
{
    int highestPriority = -1;
    for (int i = maxPriority - 1; i >= 0; i--)
    {
        if (front[i] != -1)
        {
            highestPriority = i;
            break;
        }
    }
    if (highestPriority == -1)
    {
        cout << "Queue Underflow\n";
        return;
    }
    cout << "Dequeued element with priority " << highestPriority << ": " << queue[front[highestPriority]][highestPriority].data << endl;
    if (front[highestPriority] == rear[highestPriority])
    {
        front[highestPriority] = rear[highestPriority] = -1;
    }
    else
    {
        front[highestPriority]++;
    }
}

void display(Element queue[][maxPriority], int front[], int rear[])
{
    cout << "Priority Queue elements:\n";
    for (int i = maxPriority - 1; i >= 0; i--)
    {
        cout << "Priority " << i << ": ";
        if (front[i] != -1)
        {
            for (int j = front[i]; j <= rear[i]; j++)
            {
                cout << queue[j][i].data << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    Element queue[maxQueueSize][maxPriority];
    int front[maxPriority] = {-1};
    int rear[maxPriority] = {-1};

    enqueue(queue, front, rear, 10, 2);
    enqueue(queue, front, rear, 20, 1);
    enqueue(queue, front, rear, 30, 0);
    enqueue(queue, front, rear, 40, 2);
    enqueue(queue, front, rear, 50, 1);

    display(queue, front, rear);

    dequeue(queue, front, rear);
    dequeue(queue, front, rear);

    display(queue, front, rear);

    return 0;
}
