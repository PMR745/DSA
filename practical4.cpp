#include <iostream>
#include <conio.h>
#define MAX 10
using namespace std;

struct queue
{
    int data[MAX];
    int front, rear;
};

class Queue
{
    struct queue q;

public:
    Queue() { q.front = q.rear = -1; }
    int isempty();
    int isfull();
    void enqueue(int);
    int delqueue();
    void display();
};

int Queue::isempty()
{
    return (q.front == q.rear) ? 1 : 0;
}

int Queue::isfull()
{
    return (q.rear == MAX - 1) ? 1 : 0;
}

void Queue::enqueue(int x)
{
    q.data[++q.rear] = x;
}

int Queue::delqueue()
{
    return q.data[++q.front];
}

void Queue::display()
{
    for (int i = q.front + 1; i <= q.rear; i++)
        cout << q.data[i] << " ";
}

int main()
{
    Queue obj;
    int ch, x;
    cout << "SCO_C19 Prathmesh Rajput\n";
    do
    {
        cout << "\n1. To Insert data\n";
        cout << "2. To Delete data\n";
        cout << "3. To Display data\n";
        cout << "4. To Exit\n";
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (!obj.isfull())
            {
                cout << "\nEnter data : ";

                cin >>
                    x;
                obj.enqueue(x);
            }
            else
                cout << "Queue is overflow...\n";
            break;
        case 2:
            if (!obj.isempty())
            {
                cout << "\nDeleted Element is = " << obj.delqueue();
            }
            else
            {
                cout << "\nQueue is underflow...\n";
            }
            cout << "\nRemaining Elements are : ";
            obj.display();
            break;
        case 3:
            if (!obj.isempty())
            {
                cout << "\nQueue contains : ";
                obj.display();
                cout << "\n";
            }
            else
                cout << "\nQueue is empty...\n";
            break;
        case 4:
            cout << "\nExit...";
        }
    } while (ch != 4);
    return 0;
}