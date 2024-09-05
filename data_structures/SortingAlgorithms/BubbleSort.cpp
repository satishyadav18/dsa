#include <iostream>
using namespace std;

void BubbleSort(int[], int);

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

    BubbleSort(arr, n);

    cout << "The sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            return;
        }
    }
    return;
}
