#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << abs(((a-1)/4) - ((b-1)/4)) + abs(((a-1)%4) - ((b-1)%4));
}