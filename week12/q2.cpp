#include <iostream>
using namespace std;

class Calculator
{
    int a, b, c, d;
public:
    Calculator(int x, int y, int z, int w) : a(x), b(y), c(z), d(w) {}
    void display()
    {
        cout << "Addition: " << a + b << endl;
        cout << "Subtraction: " << c - d << endl;
        cout << "Multiplication: " << a * c << endl;
        cout << "Division: " << (d != 0 ? b / d : 0) << endl;
    }
};

int main()
{
    Calculator calc(10, 20, 30, 5);
    calc.display();
    return 0;
}
