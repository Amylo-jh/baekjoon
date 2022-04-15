#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned distance, y;
    cin >> y >> distance;

    distance = distance - y;

    if(distance == 0)
    {
        cout << 0;
        return 0;
    }

    long long n;

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