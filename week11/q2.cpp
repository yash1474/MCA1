#include <iostream>
using namespace std;

int main()
{
    double a, b;
    int choice;
    cin >> a >> b >> choice;
    switch (choice)
    {
    case 1: cout << a + b; break;
    case 2: cout << a - b; break;
    case 3: cout << a * b; break;
    case 4: cout << (b != 0 ? a / b : 0); break;
    }
    return 0;
}
