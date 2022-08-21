#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int time;
        cin >> time;

        for(int i = 0; i <= 100; i++)
        {
            if(time < i * (i+1))
            {
                cout << i-1 << endl;
                break;
            }
        }
    }
}