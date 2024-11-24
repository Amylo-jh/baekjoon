#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int num, square; 
        cin >> num;
        square = num * num;

        bool flag = false;
        for(int i = 1e9; i >= 1; i/=10)
        {
            square %= i;
            if(square == num)
            {
                flag = true;
                break;
            }
        }

        if(flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}