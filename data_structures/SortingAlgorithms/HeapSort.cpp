#include <iostream>
#include<cmath>
using namespace std;

void HeapSort(int [], int);
void MakeHeap(int[], int);
void HeapAdjust(int[], int, int);

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    
    cout << "Enter data: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    HeapSort(arr, n);

    cout << "The sorted array: ";
    
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
    cout<<endl;
    return 0;
}

void HeapSort(int arr[], int n){
	MakeHeap(arr,n);
    for (int i=n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        HeapAdjust(arr, 0, i);
    }
}

void MakeHeap(int arr[], int n){
	for (int i=n/2-1;i>=0;i--){
		HeapAdjust(arr,i,n);
	}
}

void HeapAdjust(int arr[], int i, int n){
	int key=arr[i];
	int j=2*i+1;
	while(j<n){
		if(j<n-1 && arr[j]<arr[j+1]){
			j++;
		}
		if(key>=arr[j]){break;}
		arr[i]=arr[j];
		i=j;
		j=2*i+1;
	}
	arr[i]=key;
}

