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

    vector <int> field(n+2);
    vector <int> sum(n+2);

    for(int i = 1; i <= n; i++)
    {
        cin >> field[i];
    }

    for(int i = 0; i < m; i++)
    {
        int start, end, delta;
        cin >> start >> end >> delta;
        sum[start] += delta;
        sum[end+1] -= delta;
    }

    for(int i = 1; i <= n+1; i++)
    {
        sum[i] += sum[i-1];
    }

    for(int i = 1; i <= n; i++)
    {
        cout << sum[i] + field[i] << " ";
    }
}