#include <iostream>
#include <cstdio>
using namespace std;

void hannoi(int n, char from, char buffer, char to)
{
    if (n == 0)
        return;
    hannoi(n - 1, from, to, buffer);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hannoi(n - 1, buffer, from, to);
}

int main()
{
    int n;
    cin >> n;
    hannoi(n, 'A', 'B', 'C');
    return 0;
}