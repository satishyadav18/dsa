#include<iostream>
using namespace std;


void insertionSort(int a[], int n){
    for(int i=1; i<n; i++){
        int temp = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

int main(){
    int n;
    cout << "Enter the size:";
    cin >> n;
    int a[n];
    cout << "Enter the elements to be sorted: ";
    for(int i=0; i<n; i++){
    cin >> a[i];
    }
    insertionSort(a,n);
    cout << "The sorted elements are: ";
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;

}