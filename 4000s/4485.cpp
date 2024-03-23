#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int tc = 0;
    while(1)
    {
        tc++;
        int n;
        cin >> n;
        if(n == 0)
        {
            break;
        }

        vector <vector <int>> arr(n, vector <int> (n));
        vector <vector <int>> dist(n, vector <int> (n, 987654321));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        priority_queue <pair <int, pair <int, int>>> pq;
        pq.push({-arr[0][0], {0, 0}});
        dist[0][0] = arr[0][0];
        
        int dy[4] = {0, 0, 1, -1};
        int dx[4] = {1, -1, 0, 0};

        while(!pq.empty())
        {
            int cost = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(0 <= ny && ny < n && 0 <= nx && nx < n)
                {
                    if(dist[ny][nx] > cost + arr[ny][nx])
                    {
                        dist[ny][nx] = cost + arr[ny][nx];
                        pq.push({-dist[ny][nx], {nx, ny}});
                    }
                }
            }
        }

        int answer = dist[n-1][n-1];
        cout << "Problem " << tc << ": " << answer << "\n";
    }
}