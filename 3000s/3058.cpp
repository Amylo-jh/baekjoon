#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int total = 0;
        int min_even = 101;

        for(int i = 0; i < 7; i++)
        {
            int temp;
            cin >> temp;
            if(temp % 2 == 0)
            {
                total = total + temp;
                if(temp < min_even)
                {
                    min_even = temp;
                }
            }
        }

        cout << total << " " << min_even << endl;
    }
}