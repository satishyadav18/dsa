
#include<iostream>
using namespace std;

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void BubbleSort(int a[], int n){
    int passes = 0; // Counter for the number of passes
    bool swapped;

    for(int i = 0; i < n - 1; i++){
        swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(a[j + 1] < a[j]){
                swapped = true;
                swap(a[j + 1], a[j]);
            }
        }
        passes++;

        if(!swapped){
            break;
        }
    }

    cout << "Number of passes: " << passes << endl;
}

int main(){
    int n;
    cout << "Enter the size: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements in array: ";
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    BubbleSort(a, n);

    cout << "The sorted array is: ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " "; 
    }

    return 0;
}
