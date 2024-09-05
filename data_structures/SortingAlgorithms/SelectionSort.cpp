#include <iostream>
using namespace std;

void SelectionSort(int[], int);

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter data: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SelectionSort(arr, n);

    cout << "The sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (i != minIdx)
        {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
    return;
}
