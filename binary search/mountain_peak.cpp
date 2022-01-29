#include <iostream>

using namespace std;

int findPeak(int arr[],int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return e;
}

int main()
{
    int arr[] = {0, 5, 15, 2}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findPeak(arr,n) << endl;
}
