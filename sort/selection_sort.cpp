#include <iostream>

using namespace std;

int main(){
	int arr[] = {9,8,7,-1,15,6595959,1151,111,0,-1,-5,6,5,4,6,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0;i<n-1;i++){
		int small = i;
		for(int j = i+1;j<n;j++){
			if(arr[j]<arr[small]){
				small = j;
			}
		}
		if(small!=i){
			int temp = arr[i];
			arr[i] = arr[small];
			arr[small] = temp;
		}
	}
	
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<endl;
	}
	
}
