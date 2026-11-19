#include <iostream>
using namespace std;

int main()
{
    int n, choice;
    cin >> n >> choice;
    int digits[4];
    for (int i = 3; i >= 0; i--)
    {
        digits[i] = n % 10;
        n /= 10;
    }
    int reverse = digits[3] * 1000 + digits[2] * 100 + digits[1] * 10 + digits[0];
    int original = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
    if (choice == 1)
        cout << reverse;
    else if (choice == 2)
        cout << original + reverse;
    else
        cout << digits[0] + digits[2] << " " << digits[1] + digits[3];
    return 0;
}
