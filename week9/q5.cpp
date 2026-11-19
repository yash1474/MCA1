#include <iostream>
using namespace std;

void display(int a[], int index, int n)
{
    if (index == n)
        return;
    cout << a[index] << " ";
    display(a, index + 1, n);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    display(a, 0, n);
    return 0;
}
