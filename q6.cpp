#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char first[100], second[100];
    char *p1 = first, *p2 = second;
    cin.getline(p1, 100);
    cin.getline(p2, 100);
    strcat(p1, p2);
    cout << p1;
    return 0;
}