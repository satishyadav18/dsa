// quick and merge sort

#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
  int i = low, j = mid+1, k = low;
  int x[100];

  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j]) {
      x[k++] = arr[i++];
    }
    else {
      x[k++] = arr[j++];
    }

  }

  while (i <= mid) {
    x[k++] = arr[i++];
  }

  while (j <= high) {
    x[k++] = arr[j++];
  }

  for (int m = low; m <= high; m++) {
    arr[m] = x[m];
  }
}

void mergeSort(int arr[], int low, int high) {
  if (low < high) {
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
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

  mergeSort(arr, 0, n-1);

  cout << "Sorted array is: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
