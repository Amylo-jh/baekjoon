#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector <vector <int>> arr(n+1);
    for(int i = 1; i <= n; i++)
    {
        arr[i].resize(m+1);
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int k;
    cin >> k;
    for(int ii = 0; ii < k; ii++)
    {
        int x, y, xx, yy;
        int sum = 0;
        cin >> x >> y >> xx >> yy;
        for(int i = x; i <= xx; i++)
        {
            for(int j = y; j <= yy; j++)
            {
                sum += arr[i][j];
            }
        }
        cout << sum << "\n";
    }
}