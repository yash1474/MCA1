#include <iostream>
using namespace std;

int main()
{
    char str[100];
    char *ptr = str;
    cin.getline(str, 100);
    cout << ptr;
    return 0;
}