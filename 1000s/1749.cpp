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
    vector <vector <int>> pre_sum(n+1);
    arr[0].resize(m+1);
    pre_sum[0].resize(m+1);
    for(int i = 1; i <= n; i++)
    {
        arr[i].resize(m+1);
        pre_sum[i].resize(m+1);
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            pre_sum[i][j] = pre_sum[i-1][j] + pre_sum[i][j-1] + arr[i][j] - pre_sum[i-1][j-1];
        }
    }

    int answer = INT32_MIN;
    for(int row_s = 1; row_s <= n; row_s++)
    {
        for(int row_e = row_s; row_e <= n; row_e++)
        {
            for(int col_s = 1; col_s <= m; col_s++)
            {
                for(int col_e = col_s; col_e <= m; col_e++)
                {
                    answer = max(answer, pre_sum[row_e][col_e] - pre_sum[row_s-1][col_e] - pre_sum[row_e][col_s-1] + pre_sum[row_s-1][col_s-1]);
                }
            }
        }
    }

    cout << answer;
}