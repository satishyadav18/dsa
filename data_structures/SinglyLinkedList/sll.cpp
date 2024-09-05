#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
    {
        cout << "Constructor called" << endl;
        head = nullptr;
    }
    ~SinglyLinkedList()
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

    Node *getHead();
    void addBeg(int);
    void addEnd(int);
    void display();
    int delBeg();
    int delEnd();
    bool search(int);
    void reverse(Node *);
    void bubbleSort();
};

Node *SinglyLinkedList::getHead()
{
    return head;
}

void SinglyLinkedList::addBeg(int value)
{
    Node *curr = new Node;
    curr->data = value;
    curr->next = head;
    head = curr;
}

void SinglyLinkedList::addEnd(int value)
{
    Node *curr = new Node;
    curr->data = value;
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
    return;
}

void SinglyLinkedList::display()
{
    Node *temp = head;

    if (head == nullptr)
    {
        cout << "List is empty!";
    }

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int SinglyLinkedList::delBeg()
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
    return stored1;
}

int SinglyLinkedList::delEnd()
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

bool SinglyLinkedList::search(int key)
{
    if (head == nullptr)
    {
        return false;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void SinglyLinkedList::reverse(Node *r)
{
    if (r == nullptr)
    {
        return;
    }
    reverse(r->next); // using recursion
    cout << r->data << " ";
}

void SinglyLinkedList::bubbleSort()
{
    Node *temp1 = head;
    while (temp1->next != nullptr)
    {
        Node *temp2 = head;
        while (temp2->next != nullptr)
        {
            if (temp2->data > temp2->next->data)
            {
                int swapTemp = temp2->data;
                temp2->data = temp2->next->data;
                temp2->next->data = swapTemp;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return;
}

int main()
{
    SinglyLinkedList sll;
    int choice;
    int deleted1;
    int deleted2;
    bool found;
    cout << "1- addBeg, 2-addEnd, 3- display, 4- delBeg, 5- delEnd, 6- search, 7- reverse, 8- bubbleSort, 9- EXIT" << endl;
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
            int key;
            cout << "Enter data to be searched: ";
            cin >> key;
            found = sll.search(key);
            found == 1 ? (cout << "Found!" << endl) : (cout << "Not found" << endl);
            break;
        case 7:
            sll.reverse(sll.getHead());
            cout << endl;
            break;
        case 8:
            sll.bubbleSort();
            break;
        case 9:
            return 0;
            break;
        default:
            cout << "Wrong Choice!!" << endl;
            break;
        }
    } while (choice != 9);
}
