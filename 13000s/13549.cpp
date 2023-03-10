#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <bool> visited(200001);
vector <int> line(200001);

bool check_area(int pos)
{
    if(0 <= pos && pos <= 200000 && !visited[pos])
    {
        return true;
    }
    return false;
}

int main()
{
    line.assign(200001, 999999);
    
    queue <int> find_queue;
    int n, m;
    cin >> n >> m;

    find_queue.push(n);
    line[n] = 0;
    visited[n] = true;

    while(find_queue.front() != m)
    {
        int next_node = find_queue.front();
        find_queue.pop();

        if(check_area(next_node * 2))
        {
            line[next_node*2] = min(line[next_node*2], line[next_node]);
            find_queue.push(next_node*2);
            visited[next_node*2] = true;
        }
        if(check_area(next_node - 1))
        {
            line[next_node-1] = min(line[next_node-1], line[next_node] + 1);
            find_queue.push(next_node-1);
            visited[next_node-1] = true;
        }
        if(check_area(next_node + 1))
        {
            line[next_node+1] = min(line[next_node+1], line[next_node] + 1);
            find_queue.push(next_node+1);
            visited[next_node+1] = true;
        }
    }

    cout << line[m];
}