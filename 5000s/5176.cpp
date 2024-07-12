#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int p, m;
        cin >> p >> m;

        vector <int> arr(m+1);
        for(int i = 0; i < p; i++)
        {
            int seat;
            cin >> seat;
            arr[seat]++;
        }

        int ans = 0;
        for(int i = 1; i <= m; i++)
        {
            ans += max(0, arr[i] - 1);
        }

        cout << ans << '\n';
    }
}