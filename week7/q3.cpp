#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double a[n];
    double *ptr = a;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> *(ptr + i);
        sum += *(ptr + i);
    }
    double mean = sum / n;
    double variance = 0;
    for (int i = 0; i < n; i++)
        variance += (*(ptr + i) - mean) * (*(ptr + i) - mean);
    cout << "Sum = " << sum << endl;
    cout << "Mean = " << mean << endl;
    cout << "Standard Deviation = " << sqrt(variance / n);
    return 0;
}
