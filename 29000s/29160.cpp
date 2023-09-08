#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector <priority_queue <int>> player(13);
    for(int i = 0; i < n; i++)
    {
        int p, w;
        cin >> p >> w;
        player[p].push(w);
    }

    for(int i = 0; i < k; i++)
    {
        for(int j = 1; j <= 12; j++)
        {
            if(!player[j].empty())
            {
                int curr_player = player[j].top();
                player[j].pop();
                curr_player--;
                curr_player = max(0, curr_player);
                player[j].push(curr_player);
            }
        }
    }

    int total_value = 0;
    for(int i = 1; i <= 12; i++)
    {
        if(!player[i].empty())
        {
            total_value += player[i].top();
        }
    }

    cout << total_value;
}
