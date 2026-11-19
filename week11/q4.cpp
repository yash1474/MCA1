#include <iostream>
using namespace std;

int main()
{
    int n, choice;
    cin >> n >> choice;
    if (choice == 1)
    {
        if (n == 0)
        {
            cout << 0;
            return 0;
        }
        int binary[32], i = 0;
        while (n > 0)
        {
            binary[i++] = n % 2;
            n /= 2;
        }
        for (int j = i - 1; j >= 0; j--)
            cout << binary[j];
    }
    else if (choice == 2)
        cout << oct << n;
    else
        cout << hex << n;
    return 0;
}
