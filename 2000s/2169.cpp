#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> area;
vector <vector <int>> dp;
vector <vector <vector <int>>> temp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    area.resize(n);
    dp.resize(n);
    temp.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(m);
        dp[i].resize(m);
        temp[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            temp[i][j].resize(2);
            cin >> area[i][j];
            dp[i][j] = area[i][j];
        }
    }
    
    for(int i = 1; i < m; i++)
    {
        dp[0][i] = dp[0][i-1] + area[0][i];
    }

    for(int i = 1; i < n; i++)
    {
        // 위에서 내려오는것 먼저 계산
        for(int j = 0; j < m; j++)
        {
            temp[i][j][0] = dp[i-1][j] + area[i][j];
            temp[i][j][1] = dp[i-1][j] + area[i][j];
        }
        // 왼쪽으로 갈 때 계산
        for(int j = 1; j < m; j++)
        {
            temp[i][j][0] = max(temp[i][j][0], temp[i][j-1][0] + area[i][j]);
        }
        // 오른쪽으로 갈 때 계산
        for(int j = m-2; j >= 0; j--)
        {
            temp[i][j][1] = max(temp[i][j][1], temp[i][j+1][1] + area[i][j]);
        }
        // 결과값 dp테이블에 저장
        for(int j = 0; j < m; j++)
        {
            dp[i][j] = max(temp[i][j][0], temp[i][j][1]);
        }
    }

    cout << dp[n-1][m-1];
}