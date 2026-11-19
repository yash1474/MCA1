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
    for (int i = 0; i < n; i++)
        cout << *(ptr + i) << " ";
    return 0;
}
