#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

int main()
{
    int t, w;
    cin >> t >> w;
    vector <vector <vector <int>>> dp(2, vector <vector <int>> (w+1, vector <int>(t+1, -1)));
    vector <vector <vector <bool>>> visited(2, vector <vector <bool>> (w+1, vector <bool>(t+1, false)));
    queue <vector <int>> dp_queue;
    // pos, move, time = max_plums
    dp_queue.push({0, 0, 0});
    dp[0][0][0] = 0;
    visited[0][0][0] = true;
    for(int i = 0; i < t; i++)
    {
        int plum;
        cin >> plum;
        plum--;
        while(dp_queue.front()[2] == i)
        {
            int time = dp_queue.front()[2];
            int pos = dp_queue.front()[0];
            int move = dp_queue.front()[1];
            int curr_plum = dp[pos][move][time];
            dp_queue.pop();

            if(pos == plum)
            {
                dp[pos][move][time+1] = max(dp[pos][move][time+1], dp[pos][move][time]+1);
                if(!visited[pos][move][time+1])
                {
                    dp_queue.push({pos, move, time+1});
                }
                visited[pos][move][time+1] = true;
                
            }
            else
            {
                if(move+1 <= w)
                {
                    dp[!pos][move+1][time+1] = max(dp[pos][move][time]+1, dp[!pos][move+1][time+1]);
                    if(!visited[!pos][move+1][time+1])
                    {
                        dp_queue.push({!pos, move+1, time+1});
                    }
                    visited[!pos][move+1][time+1] = true;
                }

                dp[pos][move][time+1] = max(dp[pos][move][time+1], dp[pos][move][time]);
                if(!visited[pos][move][time+1])
                {
                    dp_queue.push({pos, move, time+1});
                }
                visited[pos][move][time+1] = true;
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            for(int k = 0; k <= t; k++)
            {
                answer = max(answer, dp[i][j][k]);
            }
        }
    }

    cout << answer;
}