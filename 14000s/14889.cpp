#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <vector <int>> stats(n);
    vector <int> team(n);
    for(int i = 0; i < n; i++)
    {
        if(i < n/2)
        {
            team[i] = 0;
        }
        else
        {
            team[i] = 1;
        }

        stats[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> stats[i][j];
        }
    }

    int diff = INT32_MAX;
    
    do{    
        int sum_score[2] = {0, 0};

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(team[j] == team[i])
                {
                    sum_score[team[j]] += stats[i][j];
                }
            }
        }

        diff = min(diff, abs(sum_score[0] - sum_score[1]));
    }
    while(next_permutation(team.begin(), team.end()));

    cout << diff;
}