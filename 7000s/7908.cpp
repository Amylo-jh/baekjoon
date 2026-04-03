#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (pow(2, floor(log2(n))) != n)
    {
        cout << "NIE";
    }
    else
    {
        cout << "TAK";
    }
}