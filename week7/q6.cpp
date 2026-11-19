#include <iostream>
#include <cstring>
using namespace std;

class Flight
{
    int flightNumber;
    char source[30], destination[30];
    double fare;
public:
    void setData(int number, const char s[], const char d[], double f)
    {
        flightNumber = number;
        strcpy(source, s);
        strcpy(destination, d);
        fare = f;
    }
    void display()
    {
        cout << "Flight Number: " << this->flightNumber << endl;
        cout << "Source: " << this->source << endl;
        cout << "Destination: " << this->destination << endl;
        cout << "Fare: " << this->fare << endl;
    }
};

int main()
{
    Flight f;
    f.setData(101, "Delhi", "Mumbai", 5000);
    f.display();
    return 0;
}
