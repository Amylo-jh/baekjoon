#include <iostream>

using namespace std;

int main()
{
    for(int i = 0; i < 3; i++)
    {
        int n = 0;
        for(int i = 0; i < 4; i++)
        {
            int temp;
            cin >> temp;
            n += temp;
        }

        if(n == 3)
        {
            cout << "A";
        }
        else if(n == 2)
        {
            cout << "B";
        }
        else if(n == 1)
        {
            cout << "C";
        }
        else if(n == 0)
        {
            cout << "D";
        }
        else if(n == 4)
        {
            cout << "E";
        }
        cout << "\n";
        if(cout.eof())
        {
            break;
        }
    }
}