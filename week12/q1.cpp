#include <iostream>
using namespace std;

class Example
{
    int a, b;
public:
    Example()
    {
        a = 10;
        b = 20;
    }
    void display()
    {
        cout << a << " " << b;
    }
};

int main()
{
    Example object;
    object.display();
    return 0;
}
