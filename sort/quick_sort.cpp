#include <iostream>

using namespace std;

//Partitioning Logic
int main(){
	int arr[] = {4,6,2,5,7,9,1,3};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int low = 0;
	int high = n-1;
	
	int pivot =arr[low];
	int i = low;
	int j = high;
	
	while(i<j){
	while(arr[i]<=pivot){
		i++;
	}
	while(arr[j]>pivot){
		j++;
	}
	if(i<j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	}
	
		int temp = arr[j];
		arr[j] = arr[low];
		arr[low] = temp;
	
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}
