#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence, target, replacement;
    getline(cin, sentence);
    getline(cin, target);
    getline(cin, replacement);
    size_t pos = 0;
    while ((pos = sentence.find(target, pos)) != string::npos)
    {
        sentence.replace(pos, target.length(), replacement);
        pos += replacement.length();
    }
    cout << sentence;
    return 0;
}
