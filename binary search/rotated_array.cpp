#include <iostream>

using namespace std;

int getPivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int binarySearch(int arr[], int start, int end, int key)
{
    int s = start, e = end;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int findPosition(int arr[], int key, int n)
{
    int pivot = getPivot(arr, n);
    if (key >= arr[pivot] && key <= arr[n - 1])
    {
        return binarySearch(arr, pivot, n - 1, key);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, key);
    }
}

int main()
{
    int arr[] = {9, 10, 1, 2, 3, 4, 5, 6, 7, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 4;
    cout<<"Found 4 at index : "<<findPosition(arr,4,n);
    return 0;
}
