#include <iostream>
using namespace std;

void swap_value(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_reference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a, b, choice;
    cin >> a >> b >> choice;
    switch (choice)
    {
    case 1:
        swap_value(a, b);
        cout << a << " " << b;
        break;
    case 2:
        swap_reference(a, b);
        cout << a << " " << b;
        break;
    }
    return 0;
}
