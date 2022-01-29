#include <iostream>

using namespace std;


//Question Find First and last occurrence of given number in a sorted array
int firstOccurrence(int arr[], int n, int key, bool first)
{
    int s = 0, e = n - 1;

    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e)
    {
        if (key == arr[mid])
        {
            ans = mid;
            if (first)
            {
                e = mid - 1;
            }
            else
            {
                s = mid+1;
            }
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
    return ans;
}

int main()
{
    int n = 15;
    int arr[n] = {0, 1, 2, 3, 3, 3,3,3,3,4,5,6,7,8,9};

    int key = 3;
    cout << firstOccurrence(arr, n, key, true)<<endl;
    cout << firstOccurrence(arr, n, key, false);
}