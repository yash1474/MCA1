#include <iostream>
#include <cstring>
using namespace std;

void insertSubstring(char s[], const char sub[], int pos)
{
    char temp[200];
    strncpy(temp, s, pos);
    temp[pos] = '\0';
    strcat(temp, sub);
    strcat(temp, s + pos);
    strcpy(s, temp);
}

void deleteSubstring(char s[], int pos, int n)
{
    strcpy(s + pos, s + pos + n);
}

int main()
{
    char s[200], sub[100];
    int choice, pos, n;
    cin.getline(s, 200);
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        cin.getline(sub, 100);
        cin >> pos;
        insertSubstring(s, sub, pos);
    }
    else
    {
        cin >> pos >> n;
        deleteSubstring(s, pos, n);
    }
    cout << s;
    return 0;
}
