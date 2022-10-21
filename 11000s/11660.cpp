#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, query;
    cin >> n >> query;

    vector <vector <int>> sum(n+1);
    for(int i = 1; i <= n; i++)
    {
        sum[i].resize(n+1);
        for(int j = 1; j <= n; j++)
        {
            int temp;
            cin >> temp;
            sum[i][j] += sum[i][j-1] + temp;
        }
    }

    for(int i = 0; i < query; i++)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        int query_sum = 0;
        for(int i = y1; i <= y2; i++)
        {
            query_sum += sum[i][x2] - sum[i][x1-1];
        }

        cout << query_sum << "\n";
    }
}