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
    vector <vector <int>> arr(n, vector <int>(m));
    vector <int> width_sum(m);
    vector <int> height_sum(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            height_sum[i] += arr[i][j];
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            width_sum[i] += arr[j][i];
        }
    }

    int max_perf = 0;
    for(int p = 0; p < (n+m-1); p++)
    {
        int min_value = INT32_MAX;
        pair <int, int> pos;
        for(int i = 0; i < n; i++)
        {
            if(height_sum[i] != 0 && height_sum[i] < min_value)
            {
                min_value = height_sum[i];
                pos = {i, -1};
            }
        }
        for(int i = 0; i < m; i++)
        {
            if(width_sum[i] != 0 && width_sum[i] < min_value)
            {
                min_value = width_sum[i];
                pos = {-1, i};
            }
        }
        max_perf = max(max_perf, min_value);

        if(pos.first == -1)
        {
            width_sum[pos.second] = 0;
            for(int i = 0; i < n; i++)
            {
                height_sum[i] -= arr[i][pos.second];
                arr[i][pos.second] = 0;
            }
        }
        else
        {
            height_sum[pos.first] = 0;
            for(int i = 0; i < m; i++)
            {
                width_sum[i] -= arr[pos.first][i];
                arr[pos.first][i] = 0;
            }
        }
    }
    cout << max_perf;
}