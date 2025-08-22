#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, h, l;
    cin >> n >> h >> l;
    vector <int> score(n, 1e9);
    vector <bool> visited(n, false);
    vector <vector <int>> similar(n);
    queue <int> bfs_queue;
    for(int i = 0; i < h; i++)
    {
        int temp;
        cin >> temp;
        score[temp] = 0;
        bfs_queue.push(temp);
        visited[temp] = true;
    }
    for(int i = 0; i < l; i++)
    {
        int a, b;
        cin >> a >> b;
        similar[a].push_back(b);
        similar[b].push_back(a);
    }

    while(!bfs_queue.empty())
    {
        int curr = bfs_queue.front();
        bfs_queue.pop();
        for(int i : similar[curr])
        {
            score[i] = min(score[curr]+1, score[i]);
            if(!visited[i])
            {
                bfs_queue.push(i);
                visited[i] = true;
            }
        }
    }

    int max_score = 0;
    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        if(max_score < score[i])
        {
            max_score = score[i];
            idx = i;
        }
    }

    cout << idx;
}