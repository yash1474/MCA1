#include <iostream>
#include <cstring>
using namespace std;

class pntr_obj
{
    int roll_no;
    char name[30];
public:
    void set_data(int r, const char n[])
    {
        roll_no = r;
        strcpy(name, n);
    }
    void print()
    {
        cout << "Object " << this << " has roll no " << this->roll_no << " and name " << this->name << endl;
    }
};

int main()
{
    pntr_obj obj1, obj2, obj3;
    obj1.set_data(1, "A");
    obj2.set_data(2, "B");
    obj3.set_data(3, "C");
    obj1.print();
    obj2.print();
    obj3.print();
    return 0;
}
