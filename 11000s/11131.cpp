#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n, sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            sum += temp;
        }
        if(sum < 0)
        {
            cout << "Left\n";
        }
        else if(sum > 0)
        {
            cout << "Right\n";
        }
        else
        {
            cout << "Equilibrium\n";
        }
    }
}