#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, k;
    cin >> n >> m >> k;
    
    long long count = 0;
    for(int i = 0; i < m; i++)
    {
        long long x, y;
        cin >> x >> y;
        count += y;

        if(count > k)
        {
            cout << i+1 << " " << 1;
            return 0;
        }
    }

    cout << -1;
}