#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 1; q <= tc; q++)
    {
        int a, b;
        cin >> a >> b;

        cout << "Case " << q << ": " << a + b << endl;
    }
}