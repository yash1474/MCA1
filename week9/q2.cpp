#include <iostream>
using namespace std;

void towersRecursive(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << from << " -> " << to << endl;
        return;
    }
    towersRecursive(n - 1, from, aux, to);
    cout << from << " -> " << to << endl;
    towersRecursive(n - 1, aux, to, from);
}

void towersIterative(int n)
{
    int rods[3][20], top[3] = {-1, -1, -1};
    for (int disk = n; disk >= 1; disk--)
        rods[0][++top[0]] = disk;
    int source = 0, destination = 2, auxiliary = 1;
    if (n % 2 == 0)
    {
        int temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }
    int totalMoves = (1 << n) - 1;
    for (int i = 1; i <= totalMoves; i++)
    {
        int first, second;
        if (i % 3 == 1)
        {
            first = source;
            second = destination;
        }
        else if (i % 3 == 2)
        {
            first = source;
            second = auxiliary;
        }
        else
        {
            first = auxiliary;
            second = destination;
        }
        if (top[first] == -1 || (top[second] != -1 && rods[second][top[second]] < rods[first][top[first]]))
        {
            int disk = rods[second][top[second]--];
            rods[first][++top[first]] = disk;
            cout << char('A' + second) << " -> " << char('A' + first) << endl;
        }
        else
        {
            int disk = rods[first][top[first]--];
            rods[second][++top[second]] = disk;
            cout << char('A' + first) << " -> " << char('A' + second) << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    towersRecursive(n, 'A', 'C', 'B');
    towersIterative(n);
    return 0;
}
