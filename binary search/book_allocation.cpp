#include <iostream>

using namespace std;

bool isPossibleSoln(int arr[], int mid, int n, int std)
{   
    int studentCount = 1;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (total + arr[i] <= mid)
        {
            total += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > std || arr[i] > mid)
            {
                cout << "POSSIBLE SOLUTION : false" << endl;
                return false;
            }
            total = arr[i];
        }
    }
    cout << "POSSIBLE SOLUTION : true" << endl;
    return true;
}

int main()
{
    int arr[] = {10,20,30,40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int std = 4;
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "SUM IS " << sum << endl;
    int e = sum;

    int mid = s + (e - s) / 2;

    int ans = -1;
    while (s <= e)
    {
        
        cout << "SEARCH RANGE : " << s << " TO " << e << endl;
        cout << "MID : " << mid << endl;
        if (isPossibleSoln(arr, mid, n, std))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    cout << ans;
    return 0;
}
