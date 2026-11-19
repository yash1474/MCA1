#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[100];
    cin.getline(str, 100);
    char *ptr = str;
    int count = 0;
    while (*ptr)
    {
        char ch = tolower(*ptr);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            count++;
        ptr++;
    }
    cout << count;
    return 0;
}
