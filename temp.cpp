#include <iostream>

using namespace std;

int main()
{
    int arr[6] = {5, 0, 1, 2, 3, 4};

    int res[6];
    for (int i = 0; i < 6; i++)
    {
        res[i] = arr[arr[i]];
    }

    return 0;
}
