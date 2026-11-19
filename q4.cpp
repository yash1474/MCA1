#include <iostream>
using namespace std;

int main()
{
    int value;
    int *ptr = &value;
    cin >> value;
    cout << "Incremented: " << ++(*ptr) << endl;
    cout << "Decremented: " << --(*ptr) << endl;
    return 0;
}