#include <iostream>
using namespace std;

class Example
{
    int value;
public:
    Example(int v) : value(v) {}
    Example* set(int v)
    {
        this->value = v;
        return this;
    }
    void display()
    {
        cout << this->value;
    }
};

int main()
{
    Example obj(10);
    obj.set(25)->display();
    return 0;
}
