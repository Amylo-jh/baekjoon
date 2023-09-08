#include <iostream>
#include <vector>

using namespace std;;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector <vector <int>> arr(n+1);
    for(int i = 0; i < n+1; i++)
    {
        arr[i].resize(m+1);
    }

    for(int i = 0; i < q; i++)
    {
        int t, p, v;
        cin >> t >> p >> v;
        if(t == 1)
        {
            arr[p][0] += v;
        }
        else if(t == 2)
        {
            arr[0][p] += v;
        }

    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << arr[i][0] + arr[0][j] << " ";
        }
        cout << "\n";
    }
}