#include <iostream>
using namespace std;

void MergeSort(int[], int, int);
void Merge(int[], int, int, int);

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter data: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    MergeSort(arr, 0, n-1);

    cout << "The sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}

void MergeSort(int arr[], int left, int right){
    if (left<right){
    	int mid=(left+(right-left)/2);
    	MergeSort(arr,left,mid);
    	MergeSort(arr,mid+1,right);
    	Merge(arr,left,mid,right);
    }
}

void Merge(int arr[],int low, int mid, int high){
	int i=low;
	int j=mid+1;
	int k=low;
	int B[1000];
	
	while(i<=mid && j<=high){
		if(arr[i]<=arr[j]){
			B[k++]=arr[i++];
		}
		else{
			B[k++]=arr[j++];
		}
	}
	while(i<=mid){
		B[k++]=arr[i++];
	}
	while(j<=high){
		B[k++]=arr[j++];
	}
	for (int i = low; i <= high; i++) {
	    arr[i] = B[i];
	}

}
