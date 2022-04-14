#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        unsigned distance, y;
        cin >> y >> distance;

        distance = distance - y;

        long long n;
        long long expect_distance;

        for(n = 1;; n++)
        {
            if( n*(n+1) >= distance)
            {
                break;
            }
        }
        
        if(distance > n*n)
        {
            cout << n*2 << endl;
        }
        else
        {
            cout << n*2 - 1 << endl;
        }
    }
}