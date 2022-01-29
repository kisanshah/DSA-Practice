#include<iostream>
#include<cmath>
using namespace std;

int binarySearch(int arr[],int length,int key);
int binarySearchRecursive(int arr[],int low,int high,int key);
int main(){
	int arr[] = {-2,-1,0,1,2,2,3,3,4,5,99};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<binarySearch(arr,n,2)<<endl;
	
	int low = 0;
	int high = n-1;
	cout<<binarySearchRecursive(arr,low,high,99)<<endl;
}

int binarySearchRecursive(int arr[],int low,int high,int key){
	
	if(low>high){
		return -1;
	}
	int mid = floor((low+high)/2);
	if(arr[mid]==key){
		return mid;
	}
	if(key>arr[mid]){
		return binarySearchRecursive(arr,mid+1,high,key);
	}
	if(key<arr[mid]){
		return binarySearchRecursive(arr,low,mid-1,key);
	}
}



int binarySearch(int arr[],int length,int key){
	int low = 0;
	int high = length-1;
	
	while(low<=high){
		int mid = floor((low+high)/2);
		if(key == arr[mid]){
			return mid;
		}
		else if(key>arr[mid]){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
		
	}
	return -1;
}
