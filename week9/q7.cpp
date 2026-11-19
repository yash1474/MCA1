#include <iostream>
using namespace std;

int maximum(int a[], int n)
{
    if (n == 1)
        return a[0];
    int rest = maximum(a, n - 1);
    return a[n - 1] > rest ? a[n - 1] : rest;
}

int minimum(int a[], int n)
{
    if (n == 1)
        return a[0];
    int rest = minimum(a, n - 1);
    return a[n - 1] < rest ? a[n - 1] : rest;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << maximum(a, n) << " " << minimum(a, n);
    return 0;
}
