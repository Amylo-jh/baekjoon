#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << max({a, b, c}) * 3 - a - b - c;
}