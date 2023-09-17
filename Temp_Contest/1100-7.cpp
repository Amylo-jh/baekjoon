#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <pair <long long, long long>> dots;
vector <priority_queue <pair <long long, pair <long long, long long>>, vector <pair <long long, pair <long long, long long>>>, greater<>> > dists;
vector <bool> visited;

int main()
{
    long long n;
    cin >> n;
    dots.resize(n+1);
    visited.resize(n+1);
    dists.resize(n+1);

    for(long long i = 1; i <= n; i++)
    {
        cin >> dots[i].first >> dots[i].second;
    }
    for(long long i = 1; i <= n; i++)
    {
        for(long long j = 1; j <= n; j++)
        {
            if(i == j)
            {
                continue;
            }
            else
            {
                long long dist = abs(dots[i].first - dots[j].first) + abs(dots[i].second - dots[j].second);
                dists[i].push({dist, {i, j}});
            }
        }
    }

    priority_queue <pair <long long, pair <long long, long long>>, vector <pair <long long, pair <long long, long long>>>, greater<>> pq = dists[1];
    visited[0] = true;
    while(!pq.empty())
    {
        long long curr_dist = pq.top().first;
        long long dot1 = pq.top().second.first;
        long long dot2 = pq.top().second.second;
        pq.pop();

        if(visited[dot1] && visited[dot2])
        {
            continue;
        }
        else
        {
            cout << dot1 << " " << dot2 << "\n";
            visited[dot1] = true;
            visited[dot2] = true;
            if(visited[dot1])
            {
                while(!dists[dot2].empty())
                {
                    pq.push(dists[dot2].top());
                    dists[dot2].pop();
                }
            }
            else
            {
                while(!dists[dot1].empty())
                {
                    pq.push(dists[dot1].top());
                    dists[dot1].pop();
                }
            }
        }
    }    
}