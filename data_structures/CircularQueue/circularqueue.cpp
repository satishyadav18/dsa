#include <iostream>
#include <climits>
using namespace std;

class CircularQueue
{
private:
    int front;
    int rear;
    int *arr;
    int size;

public:
    CircularQueue(int size)
    {
        cout << "Constructor called!" << endl;
        front = -1;
        rear = -1;
        this->size = size;
        arr = new int[size]; // array size determined at run-time
    }

    ~CircularQueue()
    {
        cout << "Destructor called!" << endl;
        delete[] arr;
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (front == rear + 1); // returns true if any one or both is true
    }

    bool isEmpty()
    {
        return front == -1; // returns true if this is true
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "CircularQueue is full!" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % size;
            arr[rear] = data;
            cout << "Enqueued: " << data << endl;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return INT_MIN;
        }
        else
        {
            int data = arr[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
            return data;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "CircularQueue is empty!" << endl;
        }
        else
        {
            int i = front;
            do
            {
                cout << arr[i] << " ";
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
            cout << endl;
        }
    }
};

void circularQueueOperations(CircularQueue &);

int main()
{
    CircularQueue q1(5);
    circularQueueOperations(q1);
    return 0;
}

void circularQueueOperations(CircularQueue &myObj)
{
    int choice;
    int popped;

    cout << "1- enqueue, 2- dequeue, 3- Display, 4- EXIT" << endl;
    do
    {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int ele;
            cout << "Enter data to be inserted: ";
            cin >> ele;
            myObj.enqueue(ele);
            break;
        case 2:
            popped = myObj.dequeue();
            if (popped != INT_MIN)
            {
                cout << "Dequeued: " << popped << endl;
            }
            else
            {
                cout << "CircularQueue is empty!" << endl;
            }
            break;
        case 3:
            myObj.display();
            break;
        case 4:
            return;
        default:
            cout << "Wrong Choice!" << endl;
            break;
        }
    } while (1);
}
