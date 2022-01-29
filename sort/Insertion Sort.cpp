#include <iostream>

using namespace std;

int main(){
	int arr[] = {1,-2,8,3,4,6,7,0,5,3,1,6};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i = 1;i<n;i++){
		int temp = arr[i];
		int j = i -1;
		while(arr[j]>temp && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
}
