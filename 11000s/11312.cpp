#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        long long a, b;
        cin >> a >> b;

        cout << (a/b) * (a/b) << endl;
    }
}