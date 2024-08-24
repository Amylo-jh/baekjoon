#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector <string> dna(n);
    vector <vector <int>> dp(m, vector <int> (4, 0));
    for(int i = 0; i < n; i++)
    {
        cin >> dna[i];

        for(int j = 0; j < m; j++)
        {
            if(dna[i][j] == 'A')
            {
                dp[j][0]++;
            }
            else if(dna[i][j] == 'C')
            {
                dp[j][1]++;
            }
            else if(dna[i][j] == 'G')
            {
                dp[j][2]++;
            }
            else if(dna[i][j] == 'T')
            {
                dp[j][3]++;
            }
        }
    }

    string answer;
    int hamming_dist = 0;
    for(int i = 0; i < m; i++)
    {
        int count = 0;
        int index = 0;
        for(int j = 0; j < 4; j++)
        {
            if(dp[i][j] > count)
            {
                count = dp[i][j];
                index = j;
            }
        }

        if(index == 0)
        {
            answer += 'A';
        }
        else if(index == 1)
        {
            answer += 'C';
        }
        else if(index == 2)
        {
            answer += 'G';
        }
        else if(index == 3)
        {
            answer += 'T';
        }

        hamming_dist += dp[i][0] + dp[i][1] + dp[i][2] + dp[i][3] - count;
    }

    cout << answer << "\n" << hamming_dist;

    
}