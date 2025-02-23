#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <long long>> arr(n+1, vector <long long> (m+1));
    vector <vector <int>> road(k, vector <int> (4));
    for(int i = 0; i < k; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a > c || b > d)
        {
            swap(a, c);
            swap(b, d);
        }
        road[i] = {a, b, c, d};
    }

    arr[0][0] = 1;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 && j == 0)
            {
                continue;
            }
            
            long long prev_y = 0;
            long long prev_x = 0;
            if(i > 0)
            {
                prev_y = arr[i-1][j];
                for(int l = 0; l < k; l++)
                {
                    if(road[l] == vector <int> {i-1, j, i, j})
                    {
                        prev_y = 0;
                        break;
                    }
                }
            }
            if(j > 0)
            {
                prev_x = arr[i][j-1];
                for(int l = 0; l < k; l++)
                {
                    if(road[l] == vector <int> {i, j-1, i, j})
                    {
                        prev_x = 0;
                        break;
                    }
                }
            }
            
            arr[i][j] = prev_y + prev_x;
        }
    }

    cout << arr[n][m];
}