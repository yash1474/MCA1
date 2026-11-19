#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
            return mid;
        if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n, target;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> target;
    cout << binarySearch(a, n, target);
    return 0;
}
