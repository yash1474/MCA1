#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string line, word, temp;
    getline(cin, line);
    cin >> word;
    stringstream ss(line);
    int count = 0;
    while (ss >> temp)
        if (temp == word)
            count++;
    cout << count;
    return 0;
}
