#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        int x, y, m, n, sum = 0;
        cin >> x >> y;
        if(!x && !y)
        {
            break;
        }

        vector <vector <int>> arr(x, vector <int>(y));
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y;
            arr[x][y]++;
        }
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y;
            sum += arr[x][y];
        }
        cout << sum << "\n";
    }
}