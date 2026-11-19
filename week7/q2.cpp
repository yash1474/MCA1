#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cin.getline(str, 100);
    char *ptr = str;
    int length = 0;
    while (*ptr)
    {
        length++;
        ptr++;
    }
    cout << length;
    return 0;
}
