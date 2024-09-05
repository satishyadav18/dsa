#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *last;

public:
    CircularLinkedList()
    {
        cout << "Constructor called" << endl;
        last = nullptr;
    }
    ~CircularLinkedList()
    {
        if (last == nullptr)
        {
            return;
        }
        cout << "Destructor called" << endl;
        Node *temp = last;
        temp = temp->next;
        while (temp != last)
        {
            Node *forDeleting = temp->next;
            delete temp;
            temp = forDeleting;
        }
        last = nullptr;
    }

    void addBeg(int);
    void addEnd(int);
    void display();
    int delBeg();
    int delEnd();
};

void CircularLinkedList::addBeg(int value)
{
    Node *curr = new Node;
    curr->data = value;
    if (last == nullptr)
    {
        curr->next = curr;
        last = curr;
        return;
    }
    curr->next = last->next;
    last->next = curr;
}

void CircularLinkedList::addEnd(int value)
{
    Node *curr = new Node;
    curr->data = value;
    if (last == nullptr)
    {
        curr->next = curr;
        last = curr;
        return;
    }
    curr->next = last->next;
    last->next = curr;
    last = curr;
    return;
}

void CircularLinkedList::display()
{
    Node *temp = last;

    if (last == nullptr)
    {
        cout << "List is empty!!" << endl;
        return;
    }

    temp = temp->next;
    while (temp != last)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
    cout << endl;
}

int CircularLinkedList::delBeg()
{
    if (last == nullptr)
    {
        cout << "List is empty" << endl;
        return INT_MIN;
    }
    Node *temp = last;
    temp = temp->next;
    last->next = temp->next;
    int deleted = temp->data;
    delete temp;
    return deleted;
}

int CircularLinkedList::delEnd()
{
    Node *temp = last;
    while (temp->next != last)
    {
        temp = temp->next;
    }
    temp->next = last->next;
    int deleted = last->data;
    delete last;
    last = temp;
    return deleted;
}

int main()
{
    CircularLinkedList sll;
    int choice;
    int deleted1;
    int deleted2;
    bool found;
    cout << "1- addBeg, 2-addEnd, 3- display, 4- delBeg, 5- delEnd, 6- EXIT" << endl;
    do
    {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int value1;
            cout << "Enter data: ";
            cin >> value1;
            sll.addBeg(value1);
            break;
        case 2:
            int value2;
            cout << "Enter data: ";
            cin >> value2;
            sll.addEnd(value2);
            break;
        case 3:
            sll.display();
            break;
        case 4:
            deleted1 = sll.delBeg();
            if (deleted1 != INT_MIN)
            {
                cout << "Deleted: " << deleted1 << endl;
            }
            break;
        case 5:
            deleted2 = sll.delEnd();
            if (deleted2 != INT_MIN)
            {
                cout << "Deleted: " << deleted2 << endl;
            }
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "Wrong Choice!!" << endl;
            break;
        }
    } while (choice != 6);
}
