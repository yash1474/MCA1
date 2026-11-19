#include <iostream>
using namespace std;

int main() {
    int a, b;
    int *p1 = &a, *p2 = &b;

    cin >> *p1 >> *p2;

    cout << "Sum = " << *p1 + *p2;

    return 0;
}