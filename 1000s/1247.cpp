#include <iostream>

using namespace std;

int main()
{
    for(int i = 0; i < 3; i++)
    {
        int tc;
        cin >> tc;

        __int128_t sum = 0;
        for(int j = 0; j < tc; j++)
        {
            long long temp;
            cin >> temp;
            sum += temp;
        }

        if(sum == 0)
        {
            cout << "0\n";
        }
        else if(sum > 0)
        {
            cout << "+\n";
        }
        else
        {
            cout << "-\n";
        }
    }
}