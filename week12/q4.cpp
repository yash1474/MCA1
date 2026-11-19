#include <iostream>
using namespace std;

class Counter
{
    static int count;
public:
    Counter()
    {
        count++;
    }
    ~Counter()
    {
        count--;
    }
    static int getCount()
    {
        return count;
    }
};

int Counter::count = 0;

int main()
{
    Counter *first = new Counter;
    {
        Counter second;
        cout << Counter::getCount() << endl;
    }
    cout << Counter::getCount() << endl;
    delete first;
    cout << Counter::getCount();
    return 0;
}
