#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << "int a;\n";

    for(int i = 1; i <= n; i++)
    {
        cout << "int ";

        for(int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        cout << "ptr";

        if(i != 1)
        {
            cout << i;
        }
        cout << " = &";

        if(i-1 == 0)
        {
            cout << "a";
        }
        else if(i-1 > 0)
        {
            cout << "ptr";
            if(i-1 != 1)
            {
                cout << i-1;
            }
        }
        cout << ";\n";
    }
}