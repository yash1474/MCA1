#include <iostream>
using namespace std;

int main()
{
    int value;
    int *ptr = &value;
    cin >> value;
    cout << ptr;
    return 0;
}