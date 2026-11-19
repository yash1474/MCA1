#include <iostream>
using namespace std;

int main() {
    int a, b, temp;
    int *p1 = &a, *p2 = &b;

    cin >> *p1 >> *p2;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "After swapping: " << a << " " << b;

    return 0;
}