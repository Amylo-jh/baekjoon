#include <iostream>

using namespace std;

int main()
{
    int a = 1, b = 1;
    cin >> a >> b;

    while (a + b != 0)
    {
        if(a > b)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }

        cin >> a >> b;
    }
}