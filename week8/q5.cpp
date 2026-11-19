#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    size_t pos = s.find(t);
    cout << (pos == string::npos ? -1 : (int)pos);
    return 0;
}
