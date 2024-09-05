// Heap Sort using max heap with 1-based indexing

#include<iostream>
#include<cmath>
using namespace std;

void heapify (int arr[], int i, int n) {
  // 'i' is the current node here
  // parent = i/2; //for heaps, parent's pos is always i/2 of current node
  int left = 2*i; // for heaps, left child is ALWAYS at pos: 2*i of current node
  int right = 2*i + 1; // for heaps, right child is ALWAYS at pos: 2*i+1 of current node

  int max = i;

  if (left <= n && arr[left] > arr[i]) {
    max = left;
  }

  if (right <= n && arr[right] > arr[max]) {
    max = right;
  }

  if (max != i) {
    swap(arr[i], arr[max]);
    heapify(arr, max, n);
  }
}

void makeHeap (int arr[], int n) {
  for (int i = floor(n/2.0); i >= 1; i--) {
    heapify(arr, i, n);
  }
}

void heapSort(int arr[], int n) {
  makeHeap(arr, n);
  for (int i = n; i >= 1; i--) {
    swap(arr[1], arr[i]);
    heapify(arr, 1, i-1);
  }
}

int main () {
  int n;
  cout << "Enter n: ";
  cin >> n;
  int arr[n+1]; // since we take 1-based indexing

  cout << "Enter the array: ";
  for (int i = 1; i <= n; i++) { // 1-based indexing
    cin >> arr[i];
  }

  heapSort(arr, n);

  cout << "Sorted array is: ";
  for (int i = 1; i <= n; i++) {  // 1-based indexing
    cout << arr[i] << " ";
  }

  return 0;
}