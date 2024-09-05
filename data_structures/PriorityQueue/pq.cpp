#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    int priority;
    Node *next;
};

class PriorityQueue
{
private:
    Node *head;

public:
    PriorityQueue()
    {
        // cout << "Constructor called" << endl;
        head = nullptr;
    }
    ~PriorityQueue()
    {
        // cout << "Destructor called" << endl;
        Node *temp = head;
        while (temp != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void display();
    void enqueue(int, int);
    void dequeue();
    void addPolynomials(PriorityQueue &, PriorityQueue &);
};

void PriorityQueue::display()
{
    Node *temp = head;

    if (head == nullptr)
    {
        cout << "List is empty!";
    }

    while (temp != nullptr)
    {
        cout << temp->data << "," << temp->priority << "    ";
        temp = temp->next;
    }
    cout << endl;
}

void PriorityQueue::enqueue(int value, int prior)
{
    Node *curr = new Node;
    curr->data = value;
    curr->priority = prior;
    curr->next = nullptr;

    if (head == nullptr || prior < head->priority)
    {
        curr->next = head;
        head = curr;
        return;
    }

    Node *temp = head;

    while (temp->next != nullptr && temp->next->priority <= prior)
    {
        temp = temp->next;
    }

    curr->next = temp->next;
    temp->next = curr;
    return;
}

void PriorityQueue::dequeue()
{
    if (head == nullptr)
    {
        cout << "Empty list!" << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}



// Commented out because this file has been imported in polynomial addition program. 
// The main function here works alright



// int main()
// {
//     PriorityQueue pq;
//     int choice;
//     cout << "1-enqueue, 2-dequeue, 3-display, 4-exit" << endl;
//     do
//     {
//         cout << "Enter choice: ";
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             int data;
//             cout << "Enter data: ";
//             cin >> data;
//             int prior;
//             cout << "Enter priority: ";
//             cin >> prior;
//             pq.enqueue(data, prior);
//             break;
//         case 2:
//             pq.dequeue();
//             break;
//         case 3:
//             pq.display();
//             break;
//         case 4:
//             break;
//         default:
//             cout << "Wrong choice!" << endl;
//             break;
//         }
//     } while (choice != 4);
//     return 0;
// }