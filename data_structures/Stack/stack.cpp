#include <iostream>
#include <climits>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    int *arr;

public:
    Stack(int size)
    {
        cout << "constructor called" << endl;
        this->size = size;
        top = -1;
        arr = new int[size]; // array size determined at run-time
    }

    ~Stack()
    {
        // frees the memory created for arr by constructor when program ends
        cout << "destructor called" << endl;
        delete[] arr;
    }

    bool isFull();
    bool isEmpty();
    int peek();

    void push(int);
    int pop();

    void display();
};

bool Stack::isFull()
{
    if (top == size - 1)
    {
        return 1;
    }

    return 0;
}

bool Stack::isEmpty()
{
    if (top == -1)
    {
        return 1;
    }

    return 0;
}

int Stack::peek()
{
    if (isEmpty())
    {
        return INT_MIN;
    }

    return arr[top];
}

void Stack::push(int ele)
{
    if (!isFull())
    {
        top++;
        arr[top] = ele;
        return;
    }

    cout << "Stack is full!" << endl;
}

int Stack::pop()
{
    if (!isEmpty())
    {
        int temp = top;
        top--;
        return arr[temp];
    }

    return INT_MIN;
}

void Stack::display()
{
    if (!isEmpty())
    {
        cout << "The data are: ";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    cout << "Stack is empty!!" << endl;
}

void stackOperations(Stack &myObj);

int main()
{
    Stack stack1(5);
    stackOperations(stack1);
    return 0;
}

void stackOperations(Stack &myObj)
{
    int choice;
    int peeked;
    int popped;

    cout << "1- Push, 2-Pop, 3- Display, 4- Peek, 5- EXIT" << endl;
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
            myObj.push(ele);
            break;
        case 2:
            popped = myObj.pop();
            if (popped != INT_MIN)
            {
                cout << "Popped: " << popped << endl;
            }
            else
            {
                cout << "Stack is empty!" << endl;
            }
            break;
        case 3:
            myObj.display();
            break;
        case 4:
            peeked = myObj.peek();
            if (peeked != INT_MIN)
            {
                cout << "Last element is " << peeked << endl;
            }
            else
            {
                cout << "Stack is empty!" << endl;
            }
            break;
        case 5:
            // when we used exit(0), destructor was not being called because exit(0) directly exits the program. Using 'return' will return to the main function and thus, destructor will be called
            return;
        default:
            cout << "Wrong Choice!" << endl;
            break;
        }
    } while (1);
}
