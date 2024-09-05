#include <iostream>
using namespace std;

int linearSearch(int[], int, int);

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter key: ";
    cin >> key;

    int foundAt = linearSearch(arr, n, key);
    (foundAt == -1) ? cout << "Element not found" : cout << "Element found at: " << foundAt << " [0-indexing]" << endl;
}

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }

    return -1;
}
