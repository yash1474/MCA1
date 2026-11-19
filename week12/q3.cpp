#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double hypo()
    {
        return sqrt(base * base + height * height);
    }
    double area()
    {
        return 0.5 * base * height;
    }
};

int main()
{
    double base, height;
    cin >> base >> height;
    Triangle triangle(base, height);
    cout << triangle.hypo() << " " << triangle.area();
    return 0;
}
