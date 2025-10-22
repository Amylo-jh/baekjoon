#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x, y, k;
    cin >> n >> x >> y >> k;
    x--;
    y--;
    vector <vector <vector <double>>> dp(k+1, vector <vector <double>>(n, vector <double>(n)));
    int dy[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
    int dx[8] = {2, -2, 2, -2, 1, -1, 1, -1};
    dp[0][x][y] = 1;
    for(int c = 0; c < k; c++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < 8; k++)
                {
                    int ny = i+dy[k];
                    int nx = j+dx[k];
                    if(0 <= ny && ny < n && 0 <= nx && nx < n)
                    {
                        dp[c+1][ny][nx] += dp[c][i][j]/8;
                    }
                }
            }
        }
    }

    double answer = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            answer += dp[k][i][j];
        }
    }
    cout.precision(20);
    cout << answer;
}