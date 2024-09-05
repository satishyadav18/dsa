#include <iostream>

#include <climits>

using namespace std;

class Queue {
    private: int front;
    int rear;
    int * arr;
    int size;

    public: Queue(int size) {
            cout << "Constructor called!" << endl;
            front = -1;
            rear = -1;
            this -> size = size;
            arr = new int[size]; // array size determined at run-time
        }

        ~Queue() {
            cout << "Destructor called!" << endl;
            delete[] arr;
        }

    bool isFull();
    bool isEmpty();
    void enqueue(int);
    int dequeue();
    void display();
};

bool Queue::isFull() {
    if (rear == size - 1) {
        return 1;
    }
    return 0;
}

bool Queue::isEmpty() {
    if (rear == -1 || front == rear) {
        return 1;
    }
    return 0;
}

void Queue::enqueue(int data) {
    if (!isFull()) {
        rear++;
        arr[rear] = data;
        return;
    }
    cout << "Queue is full!" << endl;
}

int Queue::dequeue() {
    if (!isEmpty()) {
        front++;
        return arr[front];
    }
    cout << "Queue is empty!" << endl;
    return INT_MIN;
}

void Queue::display() {
    if (!isEmpty()) {
        cout << "The data are: ";
        for (int i = front + 1; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    cout << "Queue is empty!" << endl;
}

void queueOperations(Queue & );

int main() {
    Queue q1(5);
    queueOperations(q1);
}

void queueOperations(Queue & myObj) {
    int choice;
    int popped;

    cout << "1- enqueue, 2-dequeue, 3- Display, 4- EXIT" << endl;
    do {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int ele;
            cout << "Enter data to be inserted: ";
            cin >> ele;
            myObj.enqueue(ele);
            break;
        case 2:
            popped = myObj.dequeue();
            if (popped != INT_MIN) {
                cout << "Popped: " << popped << endl;
            } else {
                cout << "Queue is empty!" << endl;
            }
            break;
        case 3:
            myObj.display();
            break;
        case 4:
            // when we used exit(0), destructor was not being called because exit(0) directly exits the program. Using 'return' will return to the main function and thus, destructor will be called
            return;
        default:
            cout << "Wrong Choice!" << endl;
            break;
        }
    } while (1);
}