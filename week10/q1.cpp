#include <iostream>
using namespace std;

struct Complex
{
    double real, imaginary;
};

Complex readComplex()
{
    Complex c;
    cin >> c.real >> c.imaginary;
    return c;
}

void writeComplex(Complex c)
{
    cout << c.real << " + " << c.imaginary << "i";
}

Complex addComplex(Complex a, Complex b)
{
    return {a.real + b.real, a.imaginary + b.imaginary};
}

Complex subtractComplex(Complex a, Complex b)
{
    return {a.real - b.real, a.imaginary - b.imaginary};
}

Complex multiplyComplex(Complex a, Complex b)
{
    return {a.real * b.real - a.imaginary * b.imaginary,
            a.real * b.imaginary + a.imaginary * b.real};
}

int main()
{
    Complex c1 = readComplex(), c2 = readComplex();
    cout << "Addition: ";
    writeComplex(addComplex(c1, c2));
    cout << "\nSubtraction: ";
    writeComplex(subtractComplex(c1, c2));
    cout << "\nMultiplication: ";
    writeComplex(multiplyComplex(c1, c2));
    return 0;
}
