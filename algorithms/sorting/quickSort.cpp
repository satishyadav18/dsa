#include <iostream>
using namespace std;

int lomutoPartition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[high]);
    pivot = arr[i];
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = lomutoPartition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high - 1);
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[n];

    cout << "Enter the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
