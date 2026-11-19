#include <iostream>
using namespace std;

class Numbers
{
    int value;
public:
    Numbers(int v) : value(v) {}
    int greatest(Numbers &other)
    {
        return this->value > other.value ? this->value : other.value;
    }
};

int main()
{
    int a, b;
    cin >> a >> b;
    Numbers n1(a), n2(b);
    cout << n1.greatest(n2);
    return 0;
}
