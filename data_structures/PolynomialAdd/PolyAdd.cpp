#include "E:\Codes\Data_Structures\priority_queue\pq.cpp"

void PriorityQueue::addPolynomials(PriorityQueue &p1, PriorityQueue &p2)
{
    Node *node1 = p1.head;
    Node *node2 = p2.head;

    while (node1 != nullptr && node2 != nullptr)
    {
        if (node1->priority == node2->priority)
        {
            // Add coefficients of elements with the same priority
            int sum = node1->data + node2->data;
            enqueue(sum, node1->priority); // Enqueue the sum
            node1 = node1->next;
            node2 = node2->next;
        }
        else if (node1->priority < node2->priority)
        {
            // If priority of p1 is smaller, enqueue it
            enqueue(node1->data, node1->priority);
            node1 = node1->next;
        }
        else
        {
            // If priority of p2 is smaller, enqueue it
            enqueue(node2->data, node2->priority);
            node2 = node2->next;
        }
    }

    // Enqueue any remaining elements from both queues
    while (node1 != nullptr)
    {
        enqueue(node1->data, node1->priority);
        node1 = node1->next;
    }

    while (node2 != nullptr)
    {
        enqueue(node2->data, node2->priority);
        node2 = node2->next;
    }
}

int main()
{
    PriorityQueue pq1, pq2, pq3;

    cout << endl;
    cout << "For 1st queue-" << endl;
    cout << "1- Enqueue, 2-Dequeue, 3- Display, 4-EXIT" << endl;
    int choice1;

    do
    {
        cout << "Enter choice for queue 1: ";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            int data;
            cout << "Enter data: ";
            cin >> data;
            int prior;
            cout << "Enter priority: ";
            cin >> prior;
            pq1.enqueue(data, prior);
            break;
            break;
        case 2:
            pq1.dequeue();
            break;
            break;
        case 3:
            pq1.display();
            break;
        default:
            cout << "Wrong choice!" << endl;
            break;
        }
    } while (choice1 != 4);

    cout << endl;
    cout << "For 2nd queue-" << endl;
    cout << "1- Enqueue, 2-Dequeue, 3- Display, 4-EXIT" << endl;
    int choice2;
    do
    {
        cout << "Enter choice for queue 2: ";
        cin >> choice2;
        switch (choice2)
        {
        case 1:
            int data;
            cout << "Enter data: ";
            cin >> data;
            int prior;
            cout << "Enter priority: ";
            cin >> prior;
            pq2.enqueue(data, prior);
            break;
            break;
        case 2:
            pq2.dequeue();
            break;
            break;
        case 3:
            pq2.display();
            break;
        default:
            cout << "Wrong choice!" << endl;
            break;
        }
    } while (choice2 != 4);

    cout << endl;
    pq3.addPolynomials(pq1, pq2);
    pq3.display();
    return 0;
}
