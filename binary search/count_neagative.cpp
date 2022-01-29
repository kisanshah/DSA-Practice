#include <iostream>

using namespace std;

int findNegative(int arr[], int n)
{
    int c = 0;
    int s = 0;
    int e = n - 1;
    int mid =  s + (e - s) / 2;

    while (s <= e)
    {
          cout<<"MID : "<<mid<<endl;
        if (arr[mid] < 0)
        {
            cout<<"N : "<<n<<endl;
            cout<<"MID : "<<mid<<endl;
            c = n - mid;
            e = mid - 1;
        }
        else{
            s = mid+1;
        }
        mid = s + (e - s) / 2;
    }
    return c;
}

int main()
{

    int arr[] = {5, 4, 3, 2, 1, -1, -2, -3};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findNegative(arr, n) << endl;
}