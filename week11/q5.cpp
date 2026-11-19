#include <iostream>
using namespace std;

double calculate(double a, double b, int choice)
{
    switch (choice)
    {
    case 1: return a + b;
    case 2: return a - b;
    case 3: return a * b;
    case 4: return b != 0 ? a / b : 0;
    }
    return 0;
}

int main()
{
    double a, b;
    int choice;
    cin >> a >> b >> choice;
    cout << calculate(a, b, choice);
    return 0;
}
