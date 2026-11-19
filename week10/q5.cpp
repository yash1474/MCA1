#include <iostream>
using namespace std;

struct DOB
{
    int day, month, year;
};

struct Person
{
    char name[50];
    DOB date;
};

int main()
{
    Person p;
    cin >> p.name >> p.date.day >> p.date.month >> p.date.year;
    cout << p.name << " " << p.date.day << "-" << p.date.month << "-" << p.date.year;
    return 0;
}
