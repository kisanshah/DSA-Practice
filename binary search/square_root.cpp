#include <iostream>

using namespace std;

double getPrecision(int n, int precision, int ans)
{
    double decimal = 1;
    double result = ans;
    for (int i = 0; i < precision; i++)
    {
        decimal = decimal / 10;
        for (double j = result; j * j < n; j += decimal)
        {
            result = j;
        }
    }
    return result;
}

long long int findSquareRoot(int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        long long int sqr = (mid * mid);
        if (sqr == n)
        {
            return mid;
        }
        else if (sqr < n)
        {
            ans = mid;
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
    cout << "Enter a number\n";
    int square;
    cin>> square;
    int ans = findSquareRoot(square);
    cout << "SqareRoot\n"
         << ans << endl;

    cout << "Squareroot with decimal\n"
         << getPrecision(square, 10, ans)
         << endl;
}