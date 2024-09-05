#include <iostream>
using namespace std;

int Partition(int [], int, int);
void QuickSort(int [], int, int);

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    
    cout << "Enter data: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    QuickSort(arr, 0, n-1);

    cout << "The sorted array: ";
    
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
    cout<<endl;
    return 0;
}

void QuickSort(int arr[], int low, int high){
	if(low<high){
		int x=Partition(arr,low,high);
		QuickSort(arr, low, x-1);
		QuickSort(arr, x+1, high);
	}
}

int Partition(int arr[], int low, int high){
	int pivot=arr[high];
	int i=low-1;
	int j;
	
	for (j=low;j<=high-1;j++){
		if(arr[j]<pivot){
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	
	return i+1;
}

