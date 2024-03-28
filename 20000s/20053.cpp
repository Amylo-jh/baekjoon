#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        int lo, hi;
        cin >> lo;
        hi = lo;
        for(int i = 1; i < n; i++)
        {
            int temp;
            cin >> temp;
            lo = min(lo, temp);
            hi = max(hi, temp);
        }
        cout << lo << " " << hi << "\n";
    }
}