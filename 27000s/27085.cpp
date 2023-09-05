#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> field;
vector <bool> visited;
int n;

int bfs(int s)
{
    queue <int> bfs_queue;
    bfs_queue.push(s);
    visited[s] = true;

    int score = 0;
    int max_score = 0;

    while(!bfs_queue.empty())
    {
        
    }
}

int main()
{
    int s;
    cin >> n >> s;
    s--;
    field.resize(n); 
    visited.resize(n);   
    
    for(int i = 0; i < n; i++)
    {
        cin >> field[i];
    }

    bfs(s);

}