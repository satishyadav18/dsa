#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        cout << "Constructor called" << endl;
        head = nullptr;
    }
    ~DoublyLinkedList()
    {
        cout << "Destructor called";
        Node *temp = head;
        while (temp != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void addBeg(int);
    void addEnd(int);
    int delBeg();
    int delEnd();
    int delAny(int);
    void forwardTraverse();
    void backwardTraverse();
};

void DoublyLinkedList::addBeg(int value)
{
    Node *curr = new Node;
    curr->data = value;
    curr->prev = nullptr;
    curr->next = nullptr;

    if (head == nullptr)
    {
        head = curr;
        return;
    }

    curr->next = head;
    head->prev = curr;
    head = curr;
    return;
}

void DoublyLinkedList::addEnd(int value)
{
    Node *curr = new Node;
    curr->data = value;
    curr->prev = nullptr;
    curr->next = nullptr;
    if (head == nullptr)
    {
        head = curr;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = curr;
    curr->prev = temp;
}

int DoublyLinkedList::delBeg()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return INT_MIN;
    }

    Node *temp = head;
    head = head->next;
    int stored1 = temp->data;
    delete temp;
    head->prev = nullptr;
    return stored1;
}

int DoublyLinkedList::delEnd()
{
    Node *temp = head;
    int stored2;
    if (head == nullptr) // no element present
    {
        cout << "List is empty!" << endl;
        return INT_MIN;
    }

    if (head->next == nullptr) // one element present
    {
        stored2 = head->data;
        delete head;
        head = nullptr;
        return stored2;
    }

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    stored2 = temp->next->data;
    delete temp->next;
    temp->next = nullptr;
    return stored2;
}

int DoublyLinkedList::delAny(int value)
{
    Node *temp = head;
    int stored3;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        if (temp->data == value)
        {
            if (temp == head) // one node
            {
                stored3 = delBeg();
                return stored3;
            }
            if (temp->next == nullptr) // last node
            {
                stored3 = delEnd();
                return stored3;
            }
            stored3 = temp->data;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return stored3;
        }
    }
}

void DoublyLinkedList::forwardTraverse()
{
    Node *temp = head;
    if (head == nullptr)
    {
        cout << "Empty list!" << endl;
        return;
    }

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
void DoublyLinkedList::backwardTraverse()
{
    Node *temp = head;
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    DoublyLinkedList dll;
    int choice;
    int deleted1;
    int deleted2;
    int deleted3;
    bool found;
    cout << "1- addBeg, 2- addEnd, 3- delBeg, 4- delEnd, 5- delAny, 6- forwardTraverse, 7- backwardTraverse, 8- EXIT" << endl;
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
            dll.addBeg(value1);
            break;
        case 2:
            int value2;
            cout << "Enter data: ";
            cin >> value2;
            dll.addEnd(value2);
            break;
        case 3:
            deleted1 = dll.delBeg();
            if (deleted1 != INT_MIN)
            {
                cout << "Deleted: " << deleted1 << endl;
            }
            break;
        case 4:
            deleted2 = dll.delEnd();
            if (deleted2 != INT_MIN)
            {
                cout << "Deleted: " << deleted2 << endl;
            }
            break;
        case 5:
            int key;
            cout << "Enter data to be deleted: ";
            cin >> key;
            deleted3 = dll.delAny(key);
            if (deleted3 != INT_MIN)
            {
                cout << "Deleted: " << deleted3 << endl;
            }
            else
            {
                cout << "Data not found!" << endl;
            }
            break;
        case 6:
            dll.forwardTraverse();
            break;
        case 7:
            dll.backwardTraverse();
            break;
        case 8:
            return 0;
            break;
        default:
            cout << "Wrong Choice!!" << endl;
            break;
        }
    } while (choice != 8);
}