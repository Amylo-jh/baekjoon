#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <pair <int, int>>> city(10001);
vector <bool> visited(10001);
int max_dist = 0;
int max_city = 1;

void dfs(int start_pos, int sum_dist)
{
    int return_value = start_pos;
    visited[start_pos] = true;

    for(int i = 0; i < city[start_pos].size(); i++)
    {
        if(!visited[city[start_pos][i].first])
        {
            int next_city = city[start_pos][i].first;
            int next_dist = city[start_pos][i].second + sum_dist;
            
            if(max_dist < next_dist)
            {
                max_dist = next_dist;
                max_city = next_city;
            }
            dfs(next_city, next_dist);
        }
    }
}


int main()
{
    int a = 1, b = 1, dist = 0;
    while(1)
    {
        if(cin.eof())
        {
            break;
        }

        cin >> a >> b >> dist;
        city[a].push_back(make_pair(b, dist));
        city[b].push_back(make_pair(a, dist));
    }

    dfs(a, 0);
    for(int i = 0; i <= 10000; i++)
    {
        visited[i] = false;
    }
    max_dist = 0;
    dfs(max_city, 0);

    cout << max_dist;
}