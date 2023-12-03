#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int res = 0;
    for(int i = 1; i < 10; i++)
    {
        cout << "? A " << i << endl;
        cin >> res;

        if(res == 1)
        {
            a = i;
            break;
        }
    }
    for(int i = 1; i < 10; i++)
    {
        cout << "? B " << i << endl;
        cin >> res;

        if(res == 1)
        {
            b = i;
            break;
        }
    }

    cout << "! " << a + b;
}