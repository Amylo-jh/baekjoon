#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <vector <long long>> matrix_mult(vector <vector <long long>> a, vector <vector <long long>> b)
{
    vector <vector <long long>> result(a.size(), vector <long long> (a.size(), 0));
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a.size(); j++)
        {
            for(int k = 0; k < a.size(); k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, m, kk;
    cin >> n >> k >> m;
    kk = k;

    vector <vector <vector <long long>>> dp;
    vector <vector <long long>> temp_vec(n, vector <long long> (n, 0));
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        temp_vec[i][a-1] = 1;
        temp_vec[i][b-1] = 1;
    }
    dp.push_back(temp_vec);

    int num = 1;
    while(pow(2, num) <= k)
    {
        dp.push_back(matrix_mult(dp[num-1], dp[num-1]));
        num++;
    }

    temp_vec = dp[num-1];
    k -= pow(2, num-1);
    while(k)
    {
        if(pow(2, num-1) <= k)
        {
            temp_vec = matrix_mult(temp_vec, dp[num]);
            k -= pow(2, num-1);
        }
        num--;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if(temp_vec[a-1][b-1])
        {
            cout << "death\n";
        }
        else
        {
            cout << "life\n";
        }
    }
}