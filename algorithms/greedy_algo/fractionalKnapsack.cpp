#include <iostream>
using namespace std;

struct FracType{
  double profit;
  double weight;
  double ratio;
};

void ratioArr(FracType arr[], int n) {
  for (int i = 0; i < n; i++) {
    arr[i].ratio = arr[i].profit / arr[i].weight; // basically creating ratio = profit/weight
  }
}

void addDataToArr(FracType arr[], int n) {
  arr[0].profit = 280;
  arr[0].weight = 40;
  arr[1].profit = 100;
  arr[1].weight = 10;
  arr[2].profit = 120;
  arr[2].weight = 20;
  arr[3].profit = 120;
  arr[3].weight = 24;
}

void bubbleSort(FracType arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (arr[j].ratio < arr[j+1].ratio) {
        double temp1 = arr[j].profit;
        double temp2 = arr[j].weight;
        double temp3 = arr[j].ratio;

        arr[j].profit = arr[j+1].profit;
        arr[j].weight = arr[j+1].weight;
        arr[j].ratio = arr[j+1].ratio;

        arr[j+1].profit = temp1;
        arr[j+1].weight = temp2;
        arr[j+1].ratio = temp3;
      }
    }
  }
}

void fractionalKnapsack(FracType arr[], int n, double maxWeight) {
  // creating profit/weight ratio array
  ratioArr(arr, n);

  // sort the others wrt rartio array
  bubbleSort(arr, n);

  // creating result array
  double result[n] = {0.0};

  for (int i = 0; i < n; i++) {
    if (arr[i].weight > maxWeight) {
      result[i] = maxWeight / arr[i].weight;
      break;
    }
    result[i] = 1;
    maxWeight -= arr[i].weight;
  }

  double sum = 0;
  for (int i = 0; i < n; i++) {
    cout << result[i] << " ";
    sum += arr[i].profit * result[i];
  }
  cout << endl;

  cout << "Profit is: " << sum;
}

int main() {
  int n = 4; // size of all of them
  FracType arr[n];
  addDataToArr(arr, n);

  double maxWeight = 60;

  fractionalKnapsack(arr, n, maxWeight);
  return 0;
}


// Output
// 1 1 0.5 0 
// Profit is: 440