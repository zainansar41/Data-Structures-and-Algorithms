// using class and object

#include <iostream>
using namespace std;
#define MAX 5

class Queue
{
private:
    int Array[MAX], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    // Check if the queue is full
    bool isFull()
    {
        if (front == 0 && rear == MAX - 1)
        {
            return true;
        }
        if (front == rear + 1)
        {
            return true;
        }
        return false;
    }
    // Check if the queue is empty
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    // Adding an temp
    void enQueue(int temp)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % MAX;
            Array[rear] = temp;
            cout << endl
                 << "Inserted " << temp << endl;
        }
    }
    // Removing an temp
    int deQueue()
    {
        int temp;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return (-1);
        }
        else
        {
            temp = Array[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            // Q has only one temp,
            // so we reset the queue after deleting it.
            else
            {
                front = (front + 1) % MAX;
            }
            return (temp);
        }
    }

    void display()
    {
        // Function to display status of Circular Queue
        int i;
        if (isEmpty())
        {
            cout << endl
                 << "Empty Queue" << endl;
        }
        else
        {
            cout << "Front -> " << front;
            cout << endl
                 << "elements -> ";
            for (i = front; i != rear; i = (i + 1) % MAX)
                cout << Array[i] << " ";
            cout << Array[i];
            cout << endl
                 << "Rear -> " << rear << endl;
        }
    }
};

int main()
{
    Queue q;

    // Fails because front = -1
    q.deQueue();

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    // Fails to enqueue because front == 0 && rear == MAX - 1
    q.enQueue(6);

    q.display();

    int elem = q.deQueue();

    if (elem != -1)
        cout << endl
             << "Deleted Element is " << elem << endl;

    q.display();

    q.enQueue(7);

    q.display();

    // Fails to enqueue because front == rear + 1
    q.enQueue(8);

    return 0;
}