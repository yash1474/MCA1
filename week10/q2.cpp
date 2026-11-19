#include <iostream>
#include <iomanip>
using namespace std;

struct Employee
{
    char name[50];
    double basicPay;
};

int main()
{
    Employee employees[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> employees[i].name >> employees[i].basicPay;
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
    {
        double da = 0.52 * employees[i].basicPay;
        double gross = employees[i].basicPay + da;
        cout << employees[i].name << " " << gross << endl;
    }
    return 0;
}
