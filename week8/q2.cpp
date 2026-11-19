#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[100];
    cin.getline(str, 100);
    int left = 0, right = strlen(str) - 1;
    while (left < right && str[left] == str[right])
    {
        left++;
        right--;
    }
    cout << (left >= right ? "Palindrome" : "Not Palindrome");
    return 0;
}
