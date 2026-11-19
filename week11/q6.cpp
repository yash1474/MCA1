#include <iostream>
#include <cstring>
using namespace std;

class BankAccount
{
    char name[50];
    int accountNumber;
    char type[20];
    double balance;
public:
    void assignInitial(const char n[], int number, const char t[], double amount)
    {
        strcpy(name, n);
        accountNumber = number;
        strcpy(type, t);
        balance = amount;
    }
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (amount <= balance)
            balance -= amount;
    }
    void display()
    {
        cout << name << " " << accountNumber << " " << type << " " << balance;
    }
};

int main()
{
    BankAccount account;
    account.assignInitial("Student", 1001, "Savings", 5000);
    account.deposit(1000);
    account.withdraw(2000);
    account.display();
    return 0;
}
