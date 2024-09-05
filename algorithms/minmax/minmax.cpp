// implement min and max using divide and conquer approach

#include <iostream>
using namespace std;

void minMax(int arr[], int i, int j, int &min, int &max) {
  if (i == j) {
    min = max = arr[i];
  } 
  
  else if (i + 1 == j) {
    if (arr[i] > arr[j]) {
      min = arr[j];
      max = arr[i];
    }
    else {
      min = arr[i];
      max = arr[j];
    }
  } 
  
  else {
    int mid = (i + j) / 2;
    int min1, max1;
    minMax(arr, i, mid, min, max);
    minMax(arr, mid + 1, j, min1, max1);
    min = (min1 < min) ? min1 : min;
    max = (max1 > max) ? max1 : max;
  }
}

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;
  int arr[n];
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int min, max;
  int i = 0, j = n - 1;
  minMax(arr, i, j, min, max);
  cout << "Using divide and conquer approach: Max element is " << max << ", Min element is " << min;
  return 0;
}
