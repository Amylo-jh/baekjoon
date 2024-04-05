#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, m;
        cin >> n >> m;
        vector <vector <bool>> arr(n+1, vector <bool> (1001));
        vector <int> score(m);
        for(int i = 0; i < m; i++)
        {
            cin >> score[i];
        }

        for(int i = 0; i < m; i++)
        {
            if(score[i] <= n)
            {
                arr[score[i]][score[i]] = true;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= 1000; j++)
            {
                if(!arr[i][j])
                {
                    continue;
                }
                else
                {
                    for(int k = 0; k < m; k++)
                    {
                        if(i + j + score[k] <= n && j + score[k] <= 1000)
                        {
                            arr[i + j + score[k]][j + score[k]] = true;
                        }
                    }
                }
            }
        }            
        
        int max_score = -1;
        for(int i = 0; i <= 1000; i++)
        {
            if(arr[n][i])
            {
                max_score = max(max_score, i);
            }
        }

        cout << max_score << '\n';
    }
}