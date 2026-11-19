#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int *ptr = a;
    for (int i = 0; i < n; i++)
        cin >> *(ptr + i);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += *(ptr + i);
    cout << sum;
    return 0;
}
