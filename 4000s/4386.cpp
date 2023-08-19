#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

vector <bool> selected;

int main()
{
    int n;
    cin >> n;

    selected.resize(n);
    vector <vector <pair <int, double>>> node(n);
    vector <pair <double, double>> dots(n);
    for(int i = 0; i < n; i++)
    {
        cin >> dots[i].first >> dots[i].second;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                continue;
            }
            double diff_x = abs(dots[i].first - dots[j].first);
            double diff_y = abs(dots[i].second - dots[j].second);
            diff_x = diff_x * diff_x;
            diff_y = diff_y * diff_y;
            double total_dist = sqrt(diff_x + diff_y);
            
            node[i].push_back({j, total_dist});
            node[j].push_back({i, total_dist});
        }
        
    }

    double answer = 0;
    priority_queue <pair <double, int>, vector <pair <double, int>>, greater<>> pq;
    selected[0] = true;
    for(int i = 0; i < node[0].size(); i++)
    {
        int next = node[0][i].first;
        double cost = node[0][i].second;

        pq.push({cost, next});
    }

    while(!pq.empty())
    {
        double cost = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if(!selected[curr_node])
        {
            selected[curr_node] = true;
            answer += cost;

            for(int i = 0; i < node[curr_node].size(); i++)
            {
                int next_node = node[curr_node][i].first;
                double next_cost = node[curr_node][i].second;

                if(!selected[next_node])
                {
                    pq.push({next_cost, next_node});
                }
            }
        }
    }

    cout << answer;
}