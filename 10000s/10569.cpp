#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin>> tc;

    for(int q = 0; q < tc; q++)
    {
        int a, b;
        cin >> a >> b;
        cout << 2 - a + b << endl;
    }
}