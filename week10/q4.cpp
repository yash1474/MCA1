#include <iostream>
using namespace std;

union Address
{
    char name[50];
    char home_address[100];
    char hostel_address[100];
    char city[30];
    char state[30];
    char zip[10];
};

int main()
{
    Address address;
    cin.getline(address.hostel_address, 100);
    cout << address.hostel_address;
    return 0;
}
