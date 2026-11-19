#include <iostream>
using namespace std;

long long factorialRecursive(int n)
{
    if (n <= 1)
        return 1;
    return n * factorialRecursive(n - 1);
}

long long factorial(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int gcdRecursive(int a, int b)
{
    if (b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int n, a, b, choice;
    cin >> choice;
    if (choice == 1)
    {
        cin >> n;
        cout << factorial(n) << " " << factorialRecursive(n);
    }
    else
    {
        cin >> a >> b;
        cout << gcd(a, b) << " " << gcdRecursive(a, b);
    }
    return 0;
}
