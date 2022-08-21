#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    cout << fixed;
    cout.precision(2);

    for(int q = 0; q < tc; q++)
    {
        double price;
        cin >> price;

        cout << "$" << price * 0.8 << endl;
    }
}